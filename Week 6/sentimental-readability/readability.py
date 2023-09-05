import cs50

text = input("Text: ")

letter = 0
words = 0
sentence = 0
for c in text:
    if c.isalpha():
        letter += 1
    if c.isspace():
        words += 1
    if c == "." or c == "!" or c == "?":
        sentence += 1
words += 1
L = letter / words * 100.0
S = sentence / words * 100.0

index = round(0.0588 * L - 0.296 * S - 15.8)

if index <= 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print("Grade ", index)
