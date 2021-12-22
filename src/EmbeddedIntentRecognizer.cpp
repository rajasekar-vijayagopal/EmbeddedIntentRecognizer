#include <iostream>
#include <string>
#include <regex>
#include "EmbeddedIntentRecognizer.h"

using namespace std;

/** Constructor **/
EmbeddedIntentRecognizer::EmbeddedIntentRecognizer()
:m_Weather("")
,m_Fact("")
,m_Time("")
,m_Date("")
,m_Place("")
{}

/** Destructor **/
EmbeddedIntentRecognizer::~EmbeddedIntentRecognizer(){
}

/**
Description : This function is used to get an intent
Function name : GetIntent
Arguments : string
Return : string
**/
string EmbeddedIntentRecognizer::GetIntent(const int i_countWords, char** i_words){
    string l_userInput = ConvertCharToString(i_countWords, i_words);
    return ProcessAndGetIntent(l_userInput);
}

/**
Description : This function is used to process the user input to get an intent
Function name : ProcessAndGetIntent
Arguments : string
Return : string
**/
string EmbeddedIntentRecognizer::ProcessAndGetIntent(const string i_sentence){
    string l_recognizedIntent("");
    m_Weather.clear();
    m_Fact.clear();
    m_Time.clear();
    m_Date.clear();
    m_Place.clear();

    StoreKeywords(i_sentence);

    if(m_Weather != ""){
        l_recognizedIntent.append("Intent: Get Weather");

        if(m_Place != ""){
            l_recognizedIntent.append(" City");
        }
    }
    else if(m_Fact != ""){
        l_recognizedIntent.append("Intent: Get Fact");
    }
    else{
        l_recognizedIntent.append("No Intent Recognized");
    }

    return l_recognizedIntent;
}

/**
Description : This function is used for converting the command line arguments of 2d char** to string
Function name : ConvertCharToString
Arguments : int, char**
Return : string
**/
string EmbeddedIntentRecognizer::ConvertCharToString(const int i_count, char** i_array){
    string l_sentence(i_array[0]);

    for(int i=1; i<i_count; i++)
    {
        l_sentence.append(string(" "));
        l_sentence.append(string(i_array[i]));
    }

    return l_sentence;
}

/**
Description : This function is used for storing the keywords for intents like weather, city, time and fact etc
Function name : StoreKeywords
Arguments : string
Return : void
**/
void EmbeddedIntentRecognizer::StoreKeywords(const string i_sentence){
    smatch l_matchedResult;
    regex l_searchKeyword;

    /* keywords for weather intent */
    l_searchKeyword = regex("([w|W][e|E][a|A][t|T][h|H][e|E][r|R]"
                        "|[r|R][a|A][i|I][n|N]"
                        "|[c|C][o|O][l|L][d|D]"
                        "|[d|D][r|R][y|Y]"
                        "|[h|H][o|O][t|T]"
                        "|[c|C][l|L][o|O][u|U][d|D]"
                        "|[s|S][k|K][y|Y]"
                        "|[h|H][u|U][m|M][i|I][d|D]"
                        "|[m|M][i|I][s|S][t|T]"
                        "|[s|S][u|U][n|N]"
                        "|[m|M][o|O][o|O][n|N]"
                        "|[s|S][n|N][o|O][w|W]"
                        "|[w|W][i|I][n|N][d|D]"
                        "|[s|S][t|T][r|R][o|O][m|M]"
                        "|[f|F][o|O][g|G])");

    if(regex_search(i_sentence, l_matchedResult, l_searchKeyword)){
        m_Weather = string(l_matchedResult[0]);
    }

    /* keywords for interesting fact intent */
    l_searchKeyword = regex("([f|F][a|A][c|C][t|T]"
                           "|[i|I][n|N][t|T][e|E][r|R][e|E][s|S][t|T]"
                           "|[s|S][a|A][d|D]"
                           "|[h|H][a|A][p|P][p|P][y|Y]"
                           "|[s|S][m|M][i|I][l|L][e|E]"
                           "|[a|A][n|N][g|G][e|E][r|R]"
                           "|[f|F][e|E][a|A][r|R])");

    if(regex_search(i_sentence, l_matchedResult, l_searchKeyword)){
        m_Fact = string(l_matchedResult[0]);
    }

    /* keywords for date format */
    l_searchKeyword = regex("([t|T][o|O][d|D][a|A][y|Y]"
                        "|[t|T][o|O][m|M][o|O][r|R][r|R][o|O][w|W]"
                        "|[y|Y][e|E][s|S][t|T][e|E][r|R][d|D][a|A][y|Y]"
                        "|[w|W][e|E][e|E][k|K][e|E][n|N][d|D][s|S]"
                        "|[m|M][o|O][n|N][d|D][a|A][y|Y]"
                        "|[t|T][u|U][e|E][s|S][d|D][a|A][y|Y]"
                        "|[w|W][e|E][d|D][n|N][e|E][s|S][d|D][a|A][y|Y]"
                        "|[t|T][h|H][u|U][r|R][s|S][d|D][a|A][y|Y]"
                        "|[f|F][r|R][i|I][d|D][a|A][y|Y]"
                        "|[s|S][a|A][t|T][u|U][r|R][d|D][a|A][y|Y]"
                        "|[s|S][u|U][n|N][d|D][a|A][y|Y])");

    if(regex_search(i_sentence, l_matchedResult, l_searchKeyword)){
        m_Date = string(l_matchedResult[0]);
    }

    /* keywords for places */
    l_searchKeyword = regex("([p|P][a|A][r|R][i|I][s|S]"
                        "|[b|B][e|E][r|R][l|L][i|I][n|N]"
                        "|[b|B][e|E][r|R][n|N]"
                        "|[r|R][o|O][m|M][e|E])");

    if(regex_search(i_sentence, l_matchedResult, l_searchKeyword)){
        m_Place = string(l_matchedResult[0]);
    }
}
