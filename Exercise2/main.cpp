#include <iostream>
#include <fstream>


double cambioInt(double d){
    return ((d-1)/4*3)-1;
}



int main() {
    std::ifstream data("data.csv");
    std::ofstream result("result.csv");

    if(data.fail() || result.fail()){
        std::cerr << "Errore" << std::endl;
        return 1;
    }

    // std::cout << std::fixed << std::setprecision(16);
    result << std::scientific << std::setprecision(16);
   // std::cout << cambioInt(3) << std::endl;

    double riga=0;
    data >> riga;
    double sum = cambioInt(riga);

    result << "# N Mean" << std::endl;
    result << "1 " << sum << std::endl;

    //std::cout << riga << std::endl;
    int i=2;
    while(data >> riga){
        //std::cout << riga << std::endl;
        sum = sum + cambioInt(riga);
        result << i << " " << sum/i << std::endl;
        i=i+1;

    }

    data.close();
    result.close();
    return 0;
}

