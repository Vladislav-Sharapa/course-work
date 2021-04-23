#pragma once

struct student {
	char studentName[30] = { '\0' };
	short int socialActivity = 0;
	char groupNumber[20] = { '\0' };
	double averageScore = 0;

	struct familyIncome {
		double firstIncome = 0;
		double secondIncome = 0;
		double netIncome = 0;
		bool flag = false;
	}income;
};

enum menu { setllement_of_students = 1, sharing_of_student, pop_element, edit_element, sort_element, output_element, search_info, input_data_in_file, output_data_from_file, close_program = 0 };
enum deleteAction { deletee_element = 1, leave_element };  // подумать над названием 