# tfidf
tf-idf (Term-Frequency Inverse-Document-Frequency) C++ Library

# What is TF-IDF
In information retrieval, tf–idf (also TF*IDF, TFIDF, TF–IDF, or Tf–idf), short for term frequency–inverse document frequency, is a measure of importance of a word to a document in a collection or corpus, adjusted for the fact that some words appear more frequently in general
https://en.wikipedia.org/wiki/Tf%E2%80%93idf

# Example
```cpp
#include <bits/stdc++.h>
#include "tf-idf.cpp"
using namespace std;
void setIO(string s) {
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}
int main(void){
    //Set Standard Input and Output File
    setIO("example-file.txt");

    //Read From File
    string input;
    cin >> input;

    //Noise Removal and Tokenization
    vector<string> result = tokenize(input);

    //Normalization including stopword removal and stemming
    result = normalization(result);

    //Get tf (Term Frequency)
    map<string, long long> termFrequency = tf(result);

    //Get idf (Inverse Document Frequency)
}
```
