#include <iostream>
#include <string>
#include <vector>



std::vector<int> lettercounter(std::string word){ //функция, которая считает количество каждой буквы в заданных словах
    std::vector<int> letn(26, 0);
    for(char c : word){
        letn[c - 'a']++;
    }
    return letn;
}

std::vector<int> lettercounter(std::vector<char> letters){ //функция, которая считает количество букв в letters
    std::vector<int> letn(26, 0);
    for(char c : letters){
        letn[c - 'a']++;
    }
    return letn;
}

bool possible(std::vector<int> letters, std::vector<int> letcount) { //функция для проверки, возможно ли составить слово
    for (int i = 0; i < 26; i++) {
        if (letcount[i] > letters[i]) {
            return false; 
        }
    }
    return true;
}

int scorecounter(std::vector<int> wordcount, std::vector<int> scorelist){ //Функция, подсчитывающая количество очков
    int score = 0;
    for(int i = 0; i < 26; i++){
        score += wordcount[i] * scorelist[i];
    }
    return score;
}

int main(){
std::vector<std::string> words = {"cat", "book", "apple", "sun", "happy"};
std::vector<char> letters = {'k', 'c', 'a', 'b', 'o', 't', 's', 'n', 'h', 'p', 'u'};
std::vector<int> score = { 1, 1, 1, 2, 2, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 23, 0, 0, 0, 7, 0, 0, 0, 17, 2, 0 };
std::vector<int> letcount = lettercounter(letters);

int maxscore = 0, wordscore = 0;
for (std::string s : words){
    std::vector<int> wordcount = lettercounter(s);
    bool pos = possible(letcount, wordcount);
    if(pos){
        wordscore = scorecounter(wordcount, score);
        if (wordscore > maxscore){
            maxscore = wordscore;
        }
    }
}
std::cout << maxscore;
return 0;
}

// a = 1
// b = 1
// c = 1
// d = 2
// e = 2
// f = 4
// g = 4
// h = 0
// i = 0
// j = 0
// k = 0
// l = 0
// m = 0
// n = 0
// o = 0
// p = 23
// q = 0
// r = 0
// s = 0
// t = 7
// u = 0
// v = 0
// w = 0
// x = 17
// y = 2
// z = 0
//Можно вывести слова cat и sun. Слово cat содержит 9 очков, слово sun - 0.

