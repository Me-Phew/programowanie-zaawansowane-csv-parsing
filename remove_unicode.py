# remove_unicode.py
import sys

def remove_unicode(file_name):
    with open(file_name, 'r', encoding='utf-8') as f:
        content = f.read()

    # Remove non-ASCII characters
    cleaned_content = ''.join(char for char in content if ord(char) < 128)

    with open(file_name, 'w', encoding='utf-8') as f:
        f.write(cleaned_content)

if __name__ == "__main__":
    file_name = sys.argv[1]
    remove_unicode(file_name)
