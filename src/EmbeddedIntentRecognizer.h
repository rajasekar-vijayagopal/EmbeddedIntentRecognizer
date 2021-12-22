#ifndef EMBEDDED_INTENT_RECOGNIZER_H
#define EMBEDDED_INTENT_RECOGNIZER_H

#include <string>

using namespace std;

class EmbeddedIntentRecognizer{
public:
	EmbeddedIntentRecognizer();
	~EmbeddedIntentRecognizer();

	//public member functions
    string GetIntent(const int i_countWords, char** i_words);
    string ProcessAndGetIntent(const string i_sentence);

private:
    //member variables
    string m_Weather;
    string m_Fact;
    string m_Time;
    string m_Date;
    string m_Place;

    //private member functions
    string ConvertCharToString(const int i_count, char** i_array);
    void StoreKeywords(const string i_sentence);
};

#endif
