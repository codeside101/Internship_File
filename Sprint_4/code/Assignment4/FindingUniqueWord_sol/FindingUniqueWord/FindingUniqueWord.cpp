#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <unordered_map>
#include<algorithm>
#include <cctype>

std::string readFile(const std::string& filename)
{
    std::ifstream file(filename);
    std::stringstream buffer;
    buffer << file.rdbuf();
    return buffer.str();
}

 std::unordered_map<std::string, int> countWords(const std::string& text)
{
    std::unordered_map<std::string, int> wordCount;
    std::stringstream ss(text);
    std::string word;
    while (ss >> word)
    {
        word.erase(std::remove_if(word.begin(), word.end(), ::ispunct), word.end());
        std::transform(word.begin(), word.end(), word.begin(),::tolower);
        wordCount[word]++;
    }
    return wordCount;
}

    void writeCSV(const std::unordered_map<std::string, int>& wordCount, const std::string& filename)
    {
        std::ofstream file(filename);
        file<<"word,count"<<std::endl;
        for (const auto& pair : wordCount) {
            file << pair.first << "," << pair.second << std::endl;
        }
    }
int main()
{
    std::string text = readFile("story.txt");
    std::unordered_map<std::string, int>wordCount = countWords(text);
    writeCSV(wordCount, "word_count.csv");
    std::cout << "word count has been written to the csv file" << std::endl;

    return 0;
}