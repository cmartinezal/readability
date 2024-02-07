from cs50 import get_string


def count_letters(text: str) -> int:
    """Count letters in text"""

    letter_list = [letter for letter in text if letter.isalpha()]

    return len(letter_list)


def count_words(text: str) -> int:
    """Count words in text"""

    if len(text) == 0:
        return 0

    word_count = text.count(' ')

    return word_count + 1


def count_sentences(text: str) -> int:
    """Count sentences in text"""

    if len(text) == 0:
        return 0

    sentence_count = text.count('.') + text.count('?') + text.count('!')

    return sentence_count


def get_coleman_liau_index(words: int, letters: int, sentences: int) -> int:
    """Calculate Coleman-Liau index for a text"""

    L = (letters / words) * 100
    S = (sentences / words) * 100

    index = int(round(0.0588 * L - 0.296 * S - 15.8))

    return index


def print_grade_level(index: int) -> None:
    """Print Coleman-Liau index for a text"""
    if index >= 16:
        print('Grade 16+')
    elif index < 1:
        print('Before Grade 1')
    else:
        print(f'Grade {index}')


def get_text_grade_level() -> None:
    """Outputs the grade level for a text,
    according to the Coleman-Liau formula
    """

    text = get_string("Text: ")
    letters = count_letters(text)
    words = count_words(text)
    sentences = count_sentences(text)
    index = get_coleman_liau_index(words, letters, sentences)
    print_grade_level(index)


if __name__ == "__main__":
    get_text_grade_level()
