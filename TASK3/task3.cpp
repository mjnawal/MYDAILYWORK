import random
import string

def generate_password(length, use_uppercase=True, use_numbers=True, use_special_chars=True):
    # Define character sets based on user preferences
    lowercase = string.ascii_lowercase
    uppercase = string.ascii_uppercase if use_uppercase else ''
    numbers = string.digits if use_numbers else ''
    special_chars = '@_' if use_special_chars else ''

    # Combine all the character sets
    all_characters = lowercase + uppercase + numbers + special_chars

    # Ensure that the password contains at least one character from each selected category
    password = []

    if use_uppercase:
        password.append(random.choice(uppercase))
    if use_numbers:
        password.append(random.choice(numbers))
    if use_special_chars:
        password.append(random.choice(special_chars))

    # Fill the rest of the password length with random choices from all characters
    for _ in range(length - len(password)):
        password.append(random.choice(all_characters))

    # Shuffle the list to avoid predictable sequences
    random.shuffle(password)

    return ''.join(password)

def main():
    print("Welcome to the Password Generator!")

    # Get user input for password length and complexity preferences
    while True:
        try:
            length = int(input("Enter the desired length of your password (minimum 6): "))
            if length < 6:
                print("Password length should be at least 6 characters. Please try again.")
                continue
            break
        except ValueError:
            print("Invalid input. Please enter a number.")

    use_uppercase = input("Include uppercase letters? (y/n): ").strip().lower() == 'y'
    use_numbers = input("Include numbers? (y/n): ").strip().lower() == 'y'
    use_special_chars = input("Include special characters (@ and _)? (y/n): ").strip().lower() == 'y'

    # Generate the password
    generated_password = generate_password(length, use_uppercase, use_numbers, use_special_chars)

    print(f"\nYour generated password is: {generated_password}")

if __name__ == "__main__":
    main()
