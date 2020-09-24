#include"Simhasher.h"
#include<time.h>

const char* const DICT_PATH = "dict/jieba.dict.utf8";
const char* const HMM_PATH = "dict/hmm_model.utf8";
const char* const USER_DICT_PATH = "dict/user.dict.utf8";
const char* const IDF_PATH = "dict/idf.utf8";
const char* const STOP_WORD_PATH = "dict/stop_words.utf8";

int main(int argc, char** argv) 
{
	if (argc < 4)
	{
		std::cout << "�����������\n";
		return 0;
	}

	std::clock_t c_start = std::clock();
	Simhasher sim(DICT_PATH, HMM_PATH, USER_DICT_PATH, IDF_PATH, STOP_WORD_PATH);
	if (sim.Parse(argc - 1, argv))
	{
		sim.isSimilarity(100);
	}
	std::clock_t c_end = std::clock();
	std::cout << "�ܺ�ʱ:" << static_cast<double>(c_end - c_start)/1000<<"s"<< std::endl;

	return 0;
}