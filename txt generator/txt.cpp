#include <fstream>
#include <random>

void generateRandomNumbers(const char* filename, int numLines) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100);  // generál számokat 1 és 100 között

    std::ofstream file(filename);
    if (file.is_open()) {
        for (int i = 0; i < numLines; ++i) {
            file << dis(gen) << '\n';
        }
        file.close();
    } else {
        printf("Nem sikerült megnyitni a fájlt\n");
    }
}

int main() {
    generateRandomNumbers("random.txt", 100);  // generál 100 random számot a "random_numbers.txt" fájlba
    return 0;
}