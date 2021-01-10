text = input("Text: ")

count_letters = 0 
count_words = 1 
count_sentences = 0

for letter in text:
    if letter.lower() >= 'a' and letter.lower() <= 'z':
        count_letters += 1
    if letter == ' ':
        count_words += 1
    if letter == '.' or letter == '!' or letter == '?':
        count_sentences += 1
        
average_letters = (count_letters / count_words) * 100
average_sentences = (count_sentences / count_words) * 100

index = (0.0588 * average_letters) - (0.296 * average_sentences) -15.8
grade = round(index)

if grade < 1:
    print("Before Grade 1")
elif grade >= 16:
    print("Grade 16+")
else:
    print(f"Grade {grade}");