#include "Utils.h"
#include "NaiveBayes.h"
#include "KNearestNeighbours.h"
#include "RuleBasedClassifier.h"
#include "EvaluationMeasure.h"
#include <crtdbg.h>

using namespace std;

void run_classification()
{
	vector<Instance> dataset = load_data("Diabetes.csv");
	vector<Instance> train{}, test{};
	split_data(dataset, 0.33, train, test);

	Classifier* classifier = nullptr;
	vector<int> predictions{};

	int classifier_type = 0;
	cout << "Which classifier do you want to use? \n\tInput 1 - for NaiveBayes; 2 - for KNN. 3 - for a Rule Based Classifier\n\t>> ";
	cin >> classifier_type;
	switch (classifier_type)
	{
	case 1:
	{
		classifier = new NaiveBayes{};
		break;
	}
	case 2:
	{
		int k = 0; int distance_type = 0;
		Distance* distance = nullptr;
		cout << "Input k (>0): ";
		cin >> k;
		cout << "Which type of distance do you want to use? \n\tInput 1 - for Euclidean; 2 - for Manhattan. \n\t>> ";
		cin >> distance_type;
		if (distance_type == 1)
			distance = new EuclideanDistance{};
		else
			distance = new ManhattanDistance{};
		classifier = new KNearestNeighbours{ k, distance };
		delete distance;
		break;
	}
	case 3:
	{
		classifier = new RuleBasedClassifier{};
		break;
	}
	}

	cout << "Training...\n";
	classifier->train(train);
	cout << "Testing...\n";
	predictions = classifier->predict(test);

	EvaluationMeasure* evaluation_measure = nullptr;
	int eval_type = 0;
	cout << "Which evaluation measure do you want to use? \n\tInput 1 - for accuracy; 2 - for mean squared error. \n\t>> ";
	cin >> eval_type;
	if (eval_type == 1)
	{
		evaluation_measure = new Accuracy{};
		cout << "Accuracy: ";
	}
	else
	{
		evaluation_measure = new MeanSquaredError{};
		cout << "Mean squared error: ";
	}

	try
	{
		cout << evaluation_measure->evaluate(test, predictions) << endl;
	}
	catch (runtime_error& e)
	{
		cout << "Error: " << e.what() << endl;
	}

	delete evaluation_measure;
	delete classifier;
}

int main()
{
	run_classification();
	
	_CrtDumpMemoryLeaks();

	system("pause");
	return 0;
}