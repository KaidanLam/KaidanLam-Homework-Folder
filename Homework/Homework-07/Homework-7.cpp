#include <iostream>
#include <bitset>
#include <cstdint>
#include <cstdlib>
#include <ctime>
#include <string>

class MotorStatus {
private:
    uint8_t motorState;              // Each bit represents the status of a motor (on/off)
    uint8_t overheatingMotors = 0;   // Motors that are overheating
    int turnCount;

    void initialize() {
        std::srand(time(0));
        do {
            motorState = static_cast<uint8_t>(std::rand() % 256);
        } while (motorState == 0);   // Ensure at least one motor is ON

        turnCount = 0;
        updateOverheating();
        displayStatus();
    }

    void updateOverheating() {
        if ((motorState & static_cast<uint8_t>(~overheatingMotors)) == 0) {
            // No ON motors left that are not already overheating
            turnCount++;
            return;
        } else {
            int newMotor = 0;
            do {
                newMotor = std::rand() % 8;
            } while (((static_cast<uint8_t>(1u << newMotor) & motorState) == 0) ||
                     ((static_cast<uint8_t>(1u << newMotor) & overheatingMotors) != 0));

            overheatingMotors |= static_cast<uint8_t>(1u << newMotor);
            turnCount++;
        }
    }

    void displayStatus() {
        std::cout << "Motor State (ON/OFF):   " << std::bitset<8>(motorState) << std::endl;
        std::cout << "Overheating Motors:     " << std::bitset<8>(overheatingMotors) << std::endl;
        std::cout << "Turn Count: " << turnCount << std::endl;
    }

public:
    MotorStatus() {
        initialize();
    }

    bool turnOff(uint8_t guess) {
        // Correct guess only if guess matches overheatingMotors exactly
        if (guess == overheatingMotors) {
            // Turn off only motors that are both overheating and guessed
            motorState &= static_cast<uint8_t>(~(overheatingMotors & guess));

            // Those motors are now off, so they are no longer overheating
            overheatingMotors &= static_cast<uint8_t>(~guess);

            displayStatus();
            return true;
        } else {
            // Incorrect guess: do not change motorState, only add another overheating motor
            updateOverheating();
            displayStatus();
            return false;
        }
    }
};

int checkInput(const std::string& s) {
    int value = 0;
    bool ok = true;

    // Parse binary: 8 bits only
    if (s.size() == 8 && s.find_first_not_of("01") == std::string::npos) {
        for (char c : s) {
            value = (value << 1) | (c - '0');
        }
        return value;
    }
    // Parse hex: 0x..
    else if (s.size() >= 3 && (s.rfind("0x", 0) == 0 || s.rfind("0X", 0) == 0)) {
        try {
            value = std::stoul(s, nullptr, 16);
            if (value > 255) {
                ok = false;
            }
        } catch (...) {
            ok = false;
        }

        if (ok) {
            return value;
        }
    }

    std::cout << "Invalid input. Use 8-bit binary (00101000) or hex (0x28).\n\n";
    return -1;
}

int main() {
    MotorStatus motorStatus;
    std::string s;

    std::cout << "Motor Meltdown\n";
    std::cout << "Enter your guess as:\n";
    std::cout << " - 8-bit binary (e.g., 00101000)\n";
    std::cout << " - hex (e.g., 0x28)\n";
    std::cout << "Type 'q' to quit.\n\n";

    while (true) {
        std::cout << "Your guess: ";
        std::cin >> s;

        if (!std::cin) return 0;
        if (s == "q" || s == "Q") return 0;

        int input = checkInput(s);
        if (input == -1) {
            continue;
        }

        uint8_t guess = static_cast<uint8_t>(input);

        if (motorStatus.turnOff(guess)) {
            std::cout << "Correct guess!\n";
            break;
        } else {
            std::cout << "Incorrect guess.\n\n";
        }
    }

    return 0;
}