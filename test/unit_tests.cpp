#include "gtest/gtest.h"
#include "EmbeddedIntentRecognizer.h"

EmbeddedIntentRecognizer rec; 

TEST(EmbeddedIntentRecognitionTest, WeatherTest){
    EXPECT_EQ(rec.ProcessAndGetIntent("What is the weather like today?"), "Intent: Get Weather");
    EXPECT_EQ(rec.ProcessAndGetIntent("What is the weather like in Paris today?"), "Intent: Get Weather City");
    EXPECT_EQ(rec.ProcessAndGetIntent("What is the weather like in Berlin today?"), "Intent: Get Weather City");
    EXPECT_EQ(rec.ProcessAndGetIntent("Is it hot today?"), "Intent: Get Weather");
    EXPECT_EQ(rec.ProcessAndGetIntent("Is it snowing in Bern?"), "Intent: Get Weather City");
}

TEST(EmbeddedIntentRecognitionTest, FactTest){
    EXPECT_EQ(rec.ProcessAndGetIntent("Tell me an interesting fact"), "Intent: Get Fact");
    EXPECT_EQ(rec.ProcessAndGetIntent("Smile please!!!"), "Intent: Get Fact");
    EXPECT_EQ(rec.ProcessAndGetIntent("Are you happy?"), "Intent: Get Fact");
}
