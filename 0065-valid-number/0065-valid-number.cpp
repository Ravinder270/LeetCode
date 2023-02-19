class Solution {
public:
    bool isNumber(string s) {
        return is_valid_number(s);
    }

bool is_valid_number(const std::string& s) {
    // Check for empty string
    if (s.empty()) return false;

    // Check for sign character
    size_t i = 0;
    if (s[i] == '+' || s[i] == '-') i++;

    // Check for integer part
    bool has_integer_part = false;
    while (i < s.size() && isdigit(s[i])) {
        has_integer_part = true;
        i++;
    }

    // Check for decimal part
    bool has_decimal_part = false;
    if (i < s.size() && s[i] == '.') {
        i++;
        while (i < s.size() && isdigit(s[i])) {
            has_decimal_part = true;
            i++;
        }
    }

    // Check for exponent
    if (i < s.size() && (s[i] == 'e' || s[i] == 'E')) {
        i++;

        // Check for exponent sign character
        if (i < s.size() && (s[i] == '+' || s[i] == '-')) i++;

        // Check for exponent integer part
        if (i == s.size() || !isdigit(s[i])) {
            // No integer part after exponent sign character
            return false;
        }
        while (i < s.size() && isdigit(s[i])) {
            i++;
        }
    }

    return i == s.size() && (has_integer_part || has_decimal_part);
}

};