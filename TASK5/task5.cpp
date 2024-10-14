import random

# Welcome message and rules
def display_welcome():
    print("Welcome to the Quiz Game!")
    print("Rules:")
    print("1. You will be asked a series of questions.")
    print("2. Answer each question by typing the letter of your choice or filling in the blank.")
    print("3. Your score will be displayed at the end of the quiz.")
    print("4. Have fun!\n")

# Questions and answers
questions = [
    {
        "question": "What is the capital of France?\n(a) Berlin\n(b) Madrid\n(c) Paris\n(d) Rome\n",
        "answer": "c"
    },
    {
        "question": "The Great Wall of China was primarily built for:\n(a) Trade\n(b) Defense\n(c) Tourism\n(d) Agriculture\n",
        "answer": "b"
    },
    {
        "question": "Fill in the blank: The chemical symbol for water is ____.\n",
        "answer": "H2O"
    },
    {
        "question": "Which planet is known as the Red Planet?\n(a) Earth\n(b) Mars\n(c) Jupiter\n(d) Venus\n",
        "answer": "b"
    },
    {
        "question": "Fill in the blank: The largest mammal in the world is the ____.\n",
        "answer": "blue whale"
    }
]

def run_quiz():
    score = 0
    total_questions = len(questions)

    for q in questions:
        user_answer = input(q["question"]).strip().lower()

        if user_answer == q["answer"]:
            print("Correct!\n")
            score += 1
        else:
            print(f"Incorrect! The correct answer was: {q['answer']}\n")

    # Final score
    print(f"Your final score is: {score}/{total_questions}")

if __name__ == "__main__":
    display_welcome()
    run_quiz()
