import java.util.Scanner;

public class SimpleChatbot {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String input;

        System.out.println("Hi! I'm ChatBot. Type 'bye' to exit.");

        while (true) {
            System.out.print("You: ");
            input = sc.nextLine().toLowerCase();

            if (input.contains("hi") || input.contains("hello")) {
                System.out.println("Bot: Hello there!");
            } else if (input.contains("how are you")) {
                System.out.println("Bot: I'm just code, but I'm doing fine!");
            } else if (input.contains("name")) {
                System.out.println("Bot: I'm a simple Java chatbot.");
            } else if (input.contains("bye")) {
                System.out.println("Bot: Goodbye!");
                break;
            } else {
                System.out.println("Bot: I didn't understand that.");
            }
        }

        sc.close();
    }
}
