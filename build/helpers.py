def is_roman_number(word: str) -> bool:
    """
    Check if a word is a Roman number.

    Returns:
        bool: True if the word is a Roman number, False otherwise
    """

    return word in {
        'I', 'II', 'III', 'IV', 'V', 'VI', 'VII', 'VIII'
        'IX', 'X', 'XI', 'XII', 'XIII', 'XV', 'XIX',
        'XX', 'XXI', 'XXII', 'XXIII', 'XXIV', 'XXV',
        'L',
        'C',
        'D',
        'M'
    }

def is_end_of_ordinal_number(word: str):
    """
    Check if a word is the end of an ordinal number.

    Args:
        word (str): The word to be checked.

    Returns:
        bool: True if the word is the end of an ordinal number, False otherwise.
    """

    return word in { 'st', 'rd', 'th' }
