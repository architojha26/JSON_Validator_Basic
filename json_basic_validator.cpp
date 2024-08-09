#include <iostream>
#include <stack>
#include <string>
#include <cctype>

bool isValidJSON(const std::string& json) {
    std::stack<char> stack;
    bool inString = false;
    char lastChar = '\0';

    for (size_t i = 0; i < json.length(); ++i) {
        char ch = json[i];

        // Handle string literals
        if (ch == '"' && lastChar != '\\') {
            inString = !inString;
            continue;
        }

        // Ignore characters inside strings
        if (inString) {
            lastChar = ch;
            continue;
        }

        switch (ch) {
            case '{':
            case '[':
                stack.push(ch);
                break;
            case '}':
                if (stack.empty() || stack.top() != '{') return false;
                stack.pop();
                break;
            case ']':
                if (stack.empty() || stack.top() != '[') return false;
                stack.pop();
                break;
            case ':':
                // Ensure that the colon is preceded by a key (string)
                if (lastChar != '"' && !std::isspace(lastChar)) return false;
                break;
            case ',':
                // Ensure that the comma is not misplaced
                if (lastChar != '}' && lastChar != ']' && lastChar != '"' && !std::isdigit(lastChar)) return false;
                break;
            default:
                // Validate that characters are in the correct context
                if (!std::isspace(ch) && ch != 't' && ch != 'r' && ch != 'u' && ch != 'e' && 
                    ch != 'f' && ch != 'a' && ch != 'l' && ch != 's' && 
                    ch != 'n' && ch != 'u' && ch != 'l') {
                    return false;
                }
                break;
        }

        lastChar = ch;
    }

    // Ensure all brackets are closed
    return stack.empty() && !inString;
}

int main() {
    std::string json;
    std::cout << "Enter a JSON string: ";
    std::getline(std::cin, json);

    if (isValidJSON(json)) {
        std::cout << "The JSON is valid.\n";
    } else {
        std::cout << "The JSON is invalid.\n";
    }

    return 0;
}
