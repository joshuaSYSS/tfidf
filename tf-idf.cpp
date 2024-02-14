#include <bits/stdc++.h>
//https://github.com/Blake-Madden/OleanderStemmingLibrary
#include "english_stem.h"
using namespace std;

vector<string> tokenize(string s) {
    string res = "";
    char last = '-';
    vector<string> tokenization;
    for (char& c : s) {
        if (c >= 'A' && c <= 'Z' || c >= 'a' && c <= 'z') {
            res += tolower(c);
        }
        if (c == ' ' && last != ' ') {
            tokenization.push_back(res);
            res = "";
        }
        last = c;
    }
    if(res != "") tokenization.push_back(res);
    return tokenization;
}

//https://dl.acm.org/doi/pdf/10.1145/378881.378888
set<string> stopwords = {
    "the",
    "and",
    "a",
    "that",
    "was",
    "of",
    "to",
    "in",
    "is",
    "he",
    "for",
    "it",
    "with",
    "as",
    "not",
    "his",
    "on",
    "be",
    "at",
    "by",
    "i",
    "this",
    "had",
    "but",
    "are",
    "from",
    "or",
    "have",
    "an",
    "you",
    "they",
    "which",
    "one",
    "were",
    "would",
    "her",
    "all",
    "she",
    "there",
    "will",
    "their",
    "we",
    "him",
    "been",
    "has",
    "who",
    "when",
    "more",
    "if",
    "no",
    "out",
    "so",
    "what",
    "said",
    "up",
    "its",
    "about",
    "than",
    "into",
    "them",
    "can",
    "only",
    "other",
    "new",
    "some",
    "could",
    "time",
    "these",
    "two",
    "may",
    "then",
    "first",
    "do",
    "any",
    "now",
    "my",
    "such",
    "like",
    "man",
    "over",
    "our",
    "me",
    "even",
    "most",
    "made",
    "also",
    "after",
    "did",
    "many",
    "before",
    "must",
    "through",
    "years",
    "where",
    "much",
    "back",
    "your",
    "way",
    "down",
    "well",
        "should",
        "because",

    "above",
    "across",
    "already",
    "behind",
    "cannot",
    "clear",
    "either",
    "full",
    "further",
    "gave",
    "having",
    "keep",
    "known",
    "making",
    "necessary",
    "quite",
        "really"
        "shall",
        "show",
        "sure",
        "taken",
        "therefore",
        "together",
        "whether",
        "whose",
        "yet"
};

int StringToWString(std::wstring& ws, const std::string& s)
{
    std::wstring wsTmp(s.begin(), s.end());

    ws = wsTmp;

    return 0;
}

int WStringToString(std::wstring& ws, std::string& s)
{
    std::string sTmp(ws.begin(), ws.end());

    s = sTmp;

    return 0;
}

vector<string> normalization(vector<string> s) {
    vector<string> res;
    for (string p : s) {
        stemming::english_stem<> StemEnglish;
        std::wstring word(L"");
        StringToWString(word, p);
        StemEnglish(word);
        WStringToString(word, p);

        if (stopwords.count(p)) continue;
        res.push_back(p);
    }
    return res;
}

map<string, long long> tf(vector<string> doc) {
    map<string, long long> freq;
    for (string s : doc) {
        freq[s]++;
    }
    return freq;
}

map<string, long double> idf(vector<vector<string>> docs) {
    map<string, long long> freq;
    map<string, long double> m;
    for (vector<string> doc : docs) {
        set<string> counted;
        for (string s : doc) {
            if (!counted.count(s)) freq[s]++, counted.insert(s);
        }
    }
    for (auto s : freq) {
        m[s.first] = log((long long)docs.size() / s.second) / log(10);
    }
    return m;
}
