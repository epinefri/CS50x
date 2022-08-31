-- Keep a log of any SQL queries you execute as you solve the mystery.

SELECT "Crime scene reports:";

SELECT description, street, day, month, year
FROM crime_scene_reports
WHERE day=28 AND month=7 AND year=2021;

-- > Theft took place at 10:15am at the Humphrey Street bakery

SELECT char(10);
SELECT "Interviews:";

SELECT transcript, name
FROM interviews
WHERE day=28 AND month=7 AND year=2021;

-- > within ten minutes of the theft, I saw the thief get into a car - cars that left the parking lot
-- > this morning by the ATM on Leggett Street and saw the thief there withdrawing some money
-- > As the thief was leaving the bakery, they called someone who talked to them for less than a minute. In the call, I heard the thief say that they were planning to take 
-- > the earliest flight out of Fiftyville tomorrow. The thief then asked the person on the other end of the phone to purchase the flight ticket

SELECT char(10);
SELECT "Find earliest flight with a Diana or a Bruce on board";


SELECT full_name, city, hour, minute
FROM airports
    JOIN flights ON airports.id = destination_airport_id
WHERE airports.id IN
    (SELECT destination_airport_id
    FROM flights
    WHERE id IN
        (SELECT flight_id
        FROM passengers
        WHERE passport_number IN
            (SELECT passport_number
            FROM people
            WHERE name IN ('Diana', 'Bruce')))
        AND day=29 
        AND month=7 
        AND year=2021 )
ORDER BY hour, minute;

--> earliest flights: boston 8:05, nyc 8:20

SELECT char(10);
SELECT "Suspects:";

SELECT name
FROM people
WHERE license_plate IN
    (SELECT license_plate
    FROM bakery_security_logs
    WHERE day=28 
        AND month=7 
        AND year=2021 
        AND hour=10 
        AND minute BETWEEN 15 AND 25
        AND activity = 'exit') -- people who left the bakery parking lot within 10 minutes
AND id IN
    (SELECT person_id
    FROM bank_accounts
    WHERE account_number IN
        (SELECT account_number
        FROM atm_transactions
        WHERE atm_location = 'Leggett Street'
            AND transaction_type = 'withdraw'
            AND day=28 AND month=7 AND year=2021)) -- people who withdrew money from the legget atm
AND phone_number IN
    (SELECT caller
    FROM phone_calls
    WHERE day=28 
        AND month=7 
        AND year=2021 
        AND duration<60); -- people who've had <1min calls

--> diana, bruce

SELECT char(10);
SELECT "Suspect flight passengers (potential accomplices included):";

SELECT name
FROM people
WHERE passport_number IN
    (SELECT passport_number
    FROM passengers
    WHERE flight_id IN 
        (SELECT id
        FROM flights
        WHERE destination_airport_id IN
            (SELECT id
            FROM airports
            WHERE hour BETWEEN 8 and 10 
                AND day=29 AND month=7 AND year=2021)))
AND name IN ('Diana', 'Bruce', 'Philip', 'Robin');


SELECT char(10);
SELECT "Accomplice:";

SELECT name
FROM people
WHERE phone_number IN
    (SELECT receiver
    FROM phone_calls
    WHERE day=28 
        AND month=7 
        AND year=2021 
        AND duration < 60 
        AND caller IN
            (SELECT phone_number
            FROM people
            WHERE name = 'Bruce'));

SELECT char(10);
SELECT "Destination:";


SELECT full_name, city, hour, minute
FROM airports
    JOIN flights ON airports.id = destination_airport_id
WHERE airports.id IN
    (SELECT destination_airport_id
    FROM flights
    WHERE id IN
        (SELECT flight_id
        FROM passengers
        WHERE passport_number IN
            (SELECT passport_number
            FROM people
            WHERE name = 'Bruce'))
        AND day=29 
        AND month=7 
        AND year=2021)
ORDER BY hour, minute;





