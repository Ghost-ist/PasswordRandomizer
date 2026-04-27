// Esto garantiza que al menos un caracter de cada tipo seleccionado
for (const string& pool : pools) {
    password += getRandomChar(pool);
}

uniform_int_distribution<> dist(0, allChars.size() - 1);
while (password.length() < longitud) {
    password += allChars[dist(gen)];
}

// Mezcla la contraseña
shuffle(password.begin(), password.end(), gen);

return password;
}

int main() {
    int length, quantity;
    char option;

    bool useLower = true, useUpper = true, useDigits = true, useSymbols = true;

    cout << " ====== WELCOME TO ======\n";
    cout << "=== PASSWORD GENERATOR ===\n\n";

    cout << "Password length: ";
    cin >> length;

    cout << "How may passwords?: ";
    cin >> quantity;

    cout << "\nInclude lower case letters? (s/n): ";
    cin >> option;
    useLower = (option == 's' || option == 'S');

    cout << "Include capital letters? (s/n): ";
    cin >> option;
    useUpper = (option == 's' || option == 'S');

    cout << "Include numbers? (s/n): ";
    cin >> option;
    useDigits = (option == 's' || option == 'S');

    cout << "Include symbols? (s/n): ";
    cin >> option;
    useSymbols = (option == 's' || option == 'S');

    cout << "\n=== RESULTS ===\n\n";

    for (int i = 0; i < quantity; i++) {
        string pass = generatePassword(length, useLower, useUpper, useDigits, useSymbols);
        cout << i + 1 << ". " << pass
            << "  --> Security: " << evaluateSecurity(pass) << endl;
    }

    return 0;
}