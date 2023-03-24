#include <iostream>
#include <string>
#include <vector>
#include <locale> // for the locale class
using namespace std;

// Function: Encryption
// Description: Performs Vigenere encryption and returns the result
string Encryption(string plain_text, string key)
{
    string encrypted_text = "";
    vector<int> key_number;
    for (int i = 0; i < key.length(); i++) {
        key_number.push_back((int)tolower(key[i]) - 97);
    }
    int j = 0;
    for (int i = 0; i < plain_text.length(); i++) {
        if (isalpha(plain_text[i])) {
            int letter = (((int)toupper(plain_text[i]) - 65) + key_number[j]) % 26;
            if (letter < 0) letter += 26;
            encrypted_text += (char)(letter + 65);
            j = (j + 1) % key_number.size();
        }
        else {
            encrypted_text += plain_text[i];
        }
    }
    return encrypted_text;
}

// Function: Decryption
// Description: Decrypts text encrypted using Vigenere and returns the result
string Decryption(string encrypted_text, string key)
{
    string plain_text = "";
    vector<int> key_number;
    for (int i = 0; i < key.length(); i++) {
        key_number.push_back((int)tolower(key[i]) - 97);
    }
    int j = 0;
    for (int i = 0; i < encrypted_text.length(); i++) {
        if (isalpha(encrypted_text[i])) {
            int letter = (((int)toupper(encrypted_text[i]) - 65) - key_number[j] + 26) % 26;
            if (letter < 0) letter += 26;
            plain_text += (char)(letter + 65);
            j = (j + 1) % key_number.size();
        }
        else {
            plain_text += encrypted_text[i];
        }
    }
    return plain_text;
}

int main() {
    setlocale(LC_ALL, "Turkish"); // set locale to support Turkish characters
    string plain_text = "abcçdefgğhiıjklmnoöprsştuüvyz"; // the text to be encrypted
    string key = "deceptiveabcçdefgğhiıjklmnoöprsştuüvyz"; // the key
    string encrypted_text = Encryption(plain_text, key); // encrypt the text
    string plain_text2 = Decryption(encrypted_text, key); // decrypt the encrypted text
    cout << "Plain Text: " << plain_text << endl;
    cout << "Key: " << key << endl;
    cout << "Encrypted Text: " << encrypted_text << endl;
    cout << "Decrypted Text: " << plain_text2 << endl;
    return 0;
}