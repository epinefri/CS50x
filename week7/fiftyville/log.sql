-- Keep a log of any SQL queries you execute as you solve the mystery.

SELECT description, street, day, month, year
FROM crime_scene_reports
WHERE day=28 AND month=7 AND year=2021;

-- > Theft of the CS50 duck took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today with three witnesses who were present at the time – each of their interview transcripts mentions the bakery.|Humphrey Street|28|7|2021


SELECT transcript, name
FROM interviews
WHERE day=28 AND month=7 AND year=2021;

-- > within ten minutes of the theft, I saw the thief get into a car - cars that left the parking lot
-- > this morning by the ATM on Leggett Street and saw the thief there withdrawing some money
-- > Lily's sons, Robert and Patrick, took the rooster to Paris

SELECT activity, license_plate, hour, minute
FROM bakery_security_logs
WHERE day=28 AND month=7 AND year=2021 AND hour=10 AND minute BETWEEN 15 AND 30;

-- > licence plates around 10:15

SELECT name, phone_number, passport_number, license_plate
FROM people 
WHERE id IN
    (SELECT person_id
    FROM bank_accounts
    WHERE account_number IN
        (SELECT account_number
        FROM atm_transactions
        WHERE atm_location = 'Leggett Street'
            AND transaction_type = 'withdraw'
            AND day=28 AND month=7 AND year=2021));

-- > name, phone, passport, licence plate


SELECT name
FROM people
WHERE license_plate IN 
    (SELECT license_plate
    FROM bakery_security_logs
    WHERE day=28 
        AND month=7 
        AND year=2021 
        AND hour=10 
        AND minute BETWEEN 15 AND 30)
AND id IN
    (SELECT person_id
    FROM bank_accounts
    WHERE account_number IN
        (SELECT account_number
        FROM atm_transactions
        WHERE atm_location = 'Leggett Street'
            AND transaction_type = 'withdraw'
            AND day=28 AND month=7 AND year=2021));

-- > Iman, Luca, Diana, Bruce


SELECT full_name, city FROM airports;
-- > Fiftyville Regional Airport|Fiftyville

SELECT city
FROM airports
WHERE 