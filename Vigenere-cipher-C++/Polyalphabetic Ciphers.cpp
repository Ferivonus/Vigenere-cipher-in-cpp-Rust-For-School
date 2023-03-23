#include <iostream>
#include <string>

using namespace std;

string encrypt(string plaintext, string key) {
    string ciphertext = "";
    int key_len = key.length();
    int plaintext_len = plaintext.length();

    // Iterate over each character in the plaintext
    for (int i = 0; i < plaintext_len; i++) {
        // Get the current character and convert it to uppercase
        char current_char = plaintext[i];
        current_char = toupper(current_char);

        // Calculate the index of the current character in the alphabet
        int alpha_index = current_char - 'A';

        // Calculate the index of the current character in the key
        int key_index = i % key_len;
        char key_char = key[key_index];
        key_char = toupper(key_char);
        int key_offset = key_char - 'A';

        // Calculate the new index of the current character in the alphabet
        int new_alpha_index = (alpha_index + key_offset) % 26;

        // Calculate the new character and add it to the ciphertext
        char new_char = new_alpha_index + 'A';
        ciphertext += new_char;
    }

    return ciphertext;
}

string decrypt(string ciphertext, string key) {
    string plaintext = "";
    int key_len = key.length();
    int ciphertext_len = ciphertext.length();

    // Iterate over each character in the ciphertext
    for (int i = 0; i < ciphertext_len; i++) {
        // Get the current character and convert it to uppercase
        char current_char = ciphertext[i];
        current_char = toupper(current_char);

        // Calculate the index of the current character in the alphabet
        int alpha_index = current_char - 'A';

        // Calculate the index of the current character in the key
        int key_index = i % key_len;
        char key_char = key[key_index];
        key_char = toupper(key_char);
        int key_offset = key_char - 'A';

        // Calculate the new index of the current character in the alphabet
        int new_alpha_index = (alpha_index - key_offset + 26) % 26;

        // Calculate the new character and add it to the plaintext
        char new_char = new_alpha_index + 'A';
        plaintext += new_char;
    }

    return plaintext;
}

int main() {
    //setting them in code:
    //string plaintext = "wearediscoveredsaveyourself";
    //string key = "deceptivedeceptivedeceptive";

    //setting them with hand:

    string plaintext = "";
    string key = "";

    cout << "Could u give me your plain text? uwu: ";
    getline(cin, plaintext);

    cout << "Then gimmi my key to match it uwu: ";
    getline(cin, key);

    string ciphertext = encrypt(plaintext, key);
    string decrypted_plaintext = decrypt(ciphertext, key);

    cout << "Plaintext: " << plaintext << endl;
    cout << "Key: " << key << endl;
    cout << "Ciphertext: " << ciphertext << endl;
    cout << "Decrypted plaintext: " << decrypted_plaintext << endl;

    return 0;
}