# asks the user to type in some text, and then outputs the grade level for the text, according to the Coleman-Liau formula

text = input("Text: ")

letters = 0
words = 1
sentences = 0

for i in range(len(text)):
    # Count letters
    if 65 <= ord(text[i]) <= 90 or 97 <= ord(text[i]) <= 122:
        letters += 1

    # Count words
    if ord(text[i]) == 32:
        words += 1

    # Count sentences
    if ord(text[i]) == 33 or ord(text[i]) == 46 or ord(text[i]) == 63:
        sentences += 1

# Apply Coleman-Liau index computed as 0.0588 * L - 0.296 * S - 15.8,
l = letters / words * 100
s = sentences / words * 100

index = 0.0588 * l - 0.296 * s - 15.8

# Print result
if index < 1:
    print("Before Grade 1")
if 1 < index < 16:
    print(f"Grade {round(index)}")
if index >= 16:
    print("Grade 16+")

#print(l, s, index, letters, words, sentences)