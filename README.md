# JSON Validator in C++

This project provides a basic JSON validator implemented in C++. The validator checks whether a given JSON string is well-formed by verifying its syntax, ensuring that it follows the correct structure required by the JSON format.

## Features
- **Syntax Validation:** Checks the JSON string for correct use of braces, brackets, colons, and commas.
- **String Handling:** Correctly handles string literals within the JSON to ensure they are properly formatted and closed.
- **Error Detection:** Identifies common JSON syntax errors like misplaced brackets, missing commas, or incorrect colon placements.

## How It Works

The JSON validator processes the JSON string character by character, performing various checks to validate the structure. Here's a breakdown of how the code functions:

1. **Stack for Bracket Matching:**
   - A stack is used to track opening `{` and `[` characters.
   - When a closing `}` or `]` is encountered, the stack is checked to ensure it matches the correct opening character.
   - If a mismatch is found, the JSON is considered invalid.

2. **String Handling with `inString` Flag:**
   - The `inString` boolean flag tracks whether the current character is inside a string literal.
   - Characters inside strings are not evaluated for structural syntax (e.g., braces, brackets) since they are part of the string's content.
   - The flag is toggled when a double-quote (`"`) is encountered, provided it's not escaped (i.e., preceded by a backslash `\`).

3. **Whitespace Handling with `std::isspace()`:**
   - The function `std::isspace(ch)` skips over whitespace characters like spaces, tabs, and newlines.
   - This ensures the validator only focuses on the meaningful structural elements of JSON.

4. **Colon and Comma Checks:**
   - Ensures that colons (`:`) are placed correctly between keys and values in JSON objects.
   - Commas (`,`) are checked to ensure they are correctly placed between items in arrays or between key-value pairs in objects.

5. **Final Validation:**
   - After processing the entire JSON string, the validator checks if the stack is empty and the `inString` flag is `false`.
   - An empty stack confirms that all opened braces/brackets have been properly closed.
   - If both conditions are met, the JSON is considered valid.


