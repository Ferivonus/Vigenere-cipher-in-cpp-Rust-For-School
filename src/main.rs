use std::io;

fn encrypt(plaintext: &str, key: &str) -> String {
    let mut ciphertext = String::new();
    let key_len = key.len();

    for (i, current_char) in plaintext.chars().enumerate() {
        // Get the current character and convert it to uppercase
        let mut current_char = current_char.to_ascii_uppercase();

        // Calculate the index of the current character in the alphabet
        let alpha_index = current_char as u8 - b'A';

        // Calculate the index of the current character in the key
        let key_index = i % key_len;
        let mut key_char = key.chars().nth(key_index).unwrap().to_ascii_uppercase();
        let key_offset = key_char as u8 - b'A';

        // Calculate the new index of the current character in the alphabet
        let new_alpha_index = (alpha_index + key_offset) % 26;

        // Calculate the new character and add it to the ciphertext
        let new_char = (new_alpha_index + b'A') as char;
        ciphertext.push(new_char);
    }

    ciphertext
}

fn decrypt(ciphertext: &str, key: &str) -> String {
    let mut plaintext = String::new();
    let key_len = key.len();

    for (i, current_char) in ciphertext.chars().enumerate() {
        // Get the current character and convert it to uppercase
        let mut current_char = current_char.to_ascii_uppercase();

        // Calculate the index of the current character in the alphabet
        let alpha_index = current_char as u8 - b'A';

        // Calculate the index of the current character in the key
        let key_index = i % key_len;
        let mut key_char = key.chars().nth(key_index).unwrap().to_ascii_uppercase();
        let key_offset = key_char as u8 - b'A';

        // Calculate the new index of the current character in the alphabet
        let new_alpha_index = (alpha_index + 26 - key_offset) % 26;

        // Calculate the new character and add it to the plaintext
        let new_char = (new_alpha_index + b'A') as char;
        plaintext.push(new_char);
    }

    plaintext
}

fn main() {
    println!("Please enter your plain text:");
    let mut plaintext = String::new();
    io::stdin().read_line(&mut plaintext).expect("Failed to read input.");

    println!("Please enter your key:");
    let mut key = String::new();
    io::stdin().read_line(&mut key).expect("Failed to read input.");

    let ciphertext = encrypt(&plaintext.trim(), &key.trim());
    let decrypted_plaintext = decrypt(&ciphertext, &key.trim());
    println!("");
    println!("");
    println!("Plaintext: {}", plaintext.trim());
    println!("Key: {}", key.trim());
    println!("");
    println!("Ciphertext: {}", ciphertext);
    println!("Decrypted plaintext: {}", decrypted_plaintext);
}
