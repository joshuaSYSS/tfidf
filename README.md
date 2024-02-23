# tfidf
tf-idf (Term-Frequency Inverse-Document-Frequency) C++ Library

# What is TF-IDF
In information retrieval, tf–idf, short for term frequency–inverse document frequency, is a measure of importance of a word to a document in a collection or corpus, adjusted for the fact that some words appear more frequently in general
https://en.wikipedia.org/wiki/Tf%E2%80%93idf

# What does this library do
This tfidf library offers simple functions to tokenize, stemming (Using other libraries) and other normalization on a / multiple text(s).

# Example
```cpp
#include <bits/stdc++.h>
#include "tf-idf.cpp"
using namespace std;
int main(void){
    ifstream e1("example.txt"), e2("example2.txt"), e3("example3.txt"), e4("example4.txt");
    string i1, i2, i3, i4;
    string input;
    while (getline(e1, input)) {
        i1 += input + " ";
    }
    while (getline(e2, input)) {
        i2 += input + " ";
    }
    while (getline(e3, input)) {
        i3 += input + " ";
    }
    while (getline(e4, input)) {
        i4 += input + " ";
    }

    //Lower casing, noise removal and tokenization
    vector<string> result = tokenize(i1);

    //Normalization including stopword removal and stemming
    result = normalization(result);

    //Get tf (Term Frequency) of example.txt
    map<string, long long> termFrequency = tf(result);
    for (auto x : termFrequency) {
        cout << x.first << ": " << x.second << '\n';
    }


    vector<string> result2 = tokenize(i2);
    result2 = normalization(result2);

    vector<string> result3 = tokenize(i3);
    result3 = normalization(result3);

    vector<string> result4 = tokenize(i4);
    result4 = normalization(result4);

    //Combining all poems into a collection of poems
    vector<vector<string>> v = { result, result2, result3, result4 };

    //Get idf (Inverse Document Frequency) among all these poems
    map<string, long double> inverseDocumentFrequency = idf(v);
    for (auto x : inverseDocumentFrequency) {
        cout << x.first << ": " << x.second << '\n';
    }
}
```
