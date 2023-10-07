#!/usr/bin/python3

def get_header(text: str, level: int = 1) -> str:
    assert(level <= 6)
    header = f'{level * "#"} {text} \n'
    if level == 1:
        header += '\n';
    return header

def get_entry_bullet_list(text: str) -> str:
    return f'  - {text}\n'

def get_hyperlink(url:str , text: str) -> str:
    return f'[{text}]({url})'

def get_empty_lines(num: int = 1) -> str:
    return num * '\n';


