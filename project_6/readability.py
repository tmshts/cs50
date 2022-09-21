from cs50 import get_string, get_float, get_int

text = get_string("Text: ")
#print(f"Text: {text}")
#print(f"Lenght of the text: {len(text)}")

count_letters = 0 #counter for letters
#last_char = text[-1]

for i in range(0, len(text)):
    #print(text[i])
    if text[i].islower() or text[i].isupper(): #characters contain lower or upper letter
        count_letters += 1
        #print(f"Yes letter {text[i]}") #just for checking
#print(f"Number of letters: {count_letters}")


count_words = len(text.split()) #text is split into words
#print(f"Number of words: {count_words}")


count_sentences = 0

for j in range(0, len(text)):
    if text[j] == '.' or text[j] == '!' or text[j] == '?': #characters contain . ! ?
        count_sentences += 1
#print(f"Number of sentences: {count_sentences}")

L = float(count_letters / count_words) * 100
#print(f"L is: {L}")

S = float(count_sentences / count_words) * 100
#print(f"S is: {S}")


index = 0.0588 * L - 0.296 * S - 15.8
#print(f"Index is: {index}")

grade = round(index)
#print(f"Grade is: {grade}")

if grade >= 16:
    print("Grade 16+")
elif grade < 1:
    print("Before Grade 1")
else:
    print(f"Grade {grade}")

