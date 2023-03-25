using System;
using System.Collections.Generic;
using System.Globalization; // for the TextInfo class

namespace VigenereCipher
{
    class Program
    {
        static void Main(string[] args)
        {
            string plain_text = "abcçdefgğhiıjklmnoöprsştuüvyz"; // the text to be encrypted
            string key = "deceptiveabcçdefgğhiıjklmnoöprsştuüvyz"; // the key
            string encrypted_text = Encryption(plain_text, key); // encrypt the text
            string plain_text2 = Decryption(encrypted_text, key); // decrypt the encrypted text
            Console.WriteLine("Plain Text: " + plain_text);
            Console.WriteLine("Key: " + key);
            Console.WriteLine("Encrypted Text: " + encrypted_text);
            Console.WriteLine("Decrypted Text: " + plain_text2);
        }

        // Function: Encryption
        // Description: Performs Vigenere encryption and returns the result
        static string Encryption(string plain_text, string key)
        {
            string encrypted_text = "";
            List<int> key_number = new List<int>();
            for (int i = 0; i < key.Length; i++)
            {
                key_number.Add((int)char.ToLower(key[i]) - 97);
            }
            int j = 0;
            for (int i = 0; i < plain_text.Length; i++)
            {
                if (char.IsLetter(plain_text[i]))
                {
                    int letter = (((int)char.ToUpper(plain_text[i]) - 65) + key_number[j]) % 26;
                    if (letter < 0) letter += 26;
                    encrypted_text += (char)(letter + 65);
                    j = (j + 1) % key_number.Count;
                }
                else
                {
                    encrypted_text += plain_text[i];
                }
            }
            return encrypted_text;
        }

        // Function: Decryption
        // Description: Decrypts text encrypted using Vigenere and returns the result
        static string Decryption(string encrypted_text, string key)
        {
            string plain_text = "";
            List<int> key_number = new List<int>();
            for (int i = 0; i < key.Length; i++)
            {
                key_number.Add((int)char.ToLower(key[i]) - 97);
            }
            int j = 0;
            for (int i = 0; i < encrypted_text.Length; i++)
            {
                if (char.IsLetter(encrypted_text[i]))
                {
                    int letter = (((int)char.ToUpper(encrypted_text[i]) - 65) - key_number[j] + 26) % 26;
                    if (letter < 0) letter += 26;
                    plain_text += (char)(letter + 65);
                    j = (j + 1) % key_number.Count;
                }
                else
                {
                    plain_text += encrypted_text[i];
                }
            }
            return plain_text;
        }
    }
}
