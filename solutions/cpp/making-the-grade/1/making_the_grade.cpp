#include <array>

        

          

#include <string>

        

          

#include <vector>

        

          


        

          

std::vector<int> round_down_scores(std::vector<double> student_scores) {

        

          

    std::vector<int> intVec(student_scores.begin(), student_scores.end());

        

          

    return intVec;

        

          

}

        

          


        

          

int count_failed_students(std::vector<int> student_scores) {

        

          

    int sum = 0;

        

          

    for(int i = 0; i < student_scores.size(); i++)

        

          

        sum += student_scores[i] <= 40;

        

          

    return sum;

        

          

}

        

          


        

          

std::vector<int> above_threshold(std::vector<int> student_scores, int threshold) {

        

          

    std::vector<int> overThreshhold;

        

          

    for(int i = 0; i < student_scores.size(); i++)

        

          

        if (student_scores[i] >= threshold)

        

          

            overThreshhold.push_back(student_scores[i]);

        

          

    return overThreshhold;

        

          

}

        

          


        

          

std::array<int, 4> letter_grades(int highest_score) {

        

          

    int diff = (highest_score - 40)/4;

        

          

    std::array<int, 4> value;

        

          

    for(int i = 0; i < value.size(); i++)

        

          

        value[i] = (41 + diff*i);

        

          

    return value;

        

          

}

        

          


        

          

std::vector<std::string> student_ranking(std::vector<int> student_scores, std::vector<std::string> student_names) {

        

          

    std::vector<std::string> value;

        

          

    for(int i = 0; i < student_scores.size(); i++) {

        

          

        value.push_back(std::to_string(i+1) + ". " + student_names[i] + ": " + std::to_string(student_scores[i]));

        

          

    }

        

          

    return value;

        

          

}

        

          


        

          

std::string perfect_score(std::vector<int> student_scores, std::vector<std::string> student_names) {

        

          

    for(int i = 0; i < student_scores.size(); i++)

        

          

        if (student_scores[i] == 100)

        

          

            return student_names[i];

        

          

    return "";

        

          

}