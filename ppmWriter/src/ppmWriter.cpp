#include "../include/ppmWriter.hpp"


PpmWriter::PpmWriter(){
    auto_name_set = false; //Auto Naming disabled by default
    line_length = 80; //Line length defaulted to 80 
    progress.set_todo_char(" ");
    progress.set_done_char("#");
    progress.set_opening_bracket_char("[");
    progress.set_closing_bracket_char("]");
    progress.show_bar(true);

}

std::string PpmWriter::getAutoFileName(){
    std::stringstream auto_file_name_s;
    auto now = std::chrono::system_clock::now();
    std::time_t time = std::chrono::system_clock::to_time_t(now);
    auto_file_name_s << time << ".ppm";
    return auto_file_name_s.str();
}

int PpmWriter::write(std::string filename, int width, int height, int color_max, std::string comments, Color image[]){
    //----------Setting output file name -----------//
    std::string output_file_name;
    if(auto_name_set){
        output_file_name = getAutoFileName();
    }
    else{
        output_file_name = filename;
    }
    //----------------------------------------------//
    std::ofstream output_stream(output_file_name, std::ios::out | std::ios::binary);
    //-----------Writing Head----------------//
    output_stream << "P3\n"
    << "#" << comments << "\n"
    << width << " " << height << "\n"
    << color_max << "\n";
    //-----------Writing colors-------------//
    int print_count = 0;
    for(uint32_t j=0;j<height;j++){
        for(uint32_t i=0;i<width;i++){
            for(uint32_t k=0;k<3;k++){
                output_stream << image[i*j][k] << " "; //this will change
                print_count++;
                if(print_count % line_length == 0){
                    output_stream << "\n";
                }
            }

        }
    }
    //--------------------------------------//
    output_stream.close();
    return 0;
    //std::ofstream filename
    
}

int PpmWriter::write(std::string filename, int width, int height, int color_max, std::string comments, Color color_const){

    //----------Setting output file name -----------//
    std::string output_file_name;
    if(auto_name_set){
        output_file_name = getAutoFileName();
    }
    else{
        output_file_name = filename;
    }
    //----------------------------------------------//
    std::ofstream output_stream(output_file_name, std::ios::out | std::ios::binary);
    //-----------Writing Head----------------//
    output_stream << "P3\n"
    << "#" << comments << "\n"
    << width << " " << height << "\n"
    << color_max << "\n";
    //-----------Writing colors-------------//
    int print_count = 0;
    for(uint32_t j=0;j<height;j++){
        for(uint32_t i=0;i<width;i++){
            for(uint32_t k=0;k<color_const.size();k++){
                output_stream << color_const[k] << " ";
                print_count++;
                if(print_count % line_length == 0){
                    output_stream << "\n";
                }
            }

        }
    }
    //--------------------------------------//
    output_stream.close();
    return 0;
    //std::ofstream filename
}


int PpmWriter::write(std::string filename, int width, int height, int color_max, std::string comments, std::function<Color (int,int,int,int)> pattern){
      //----------Setting output file name -----------//
    std::string output_file_name;
    progress.set_niter(height);
    if(auto_name_set){
        output_file_name = getAutoFileName();
    }
    else{
        output_file_name = filename;
    }
    //----------------------------------------------//
    std::ofstream output_stream(output_file_name, std::ios::out | std::ios::binary);
    //-----------Writing Head----------------//
    output_stream << "P3\n"
    << "#" << comments << "\n"
    << width << " " << height << "\n"
    << color_max << "\n";
    //-----------Writing colors-------------//
    int print_count = 0;
    int pixel_count = 0;

    for(int j=0;j<height;j++){
        for(int i=0;i<width;i++){
            Color pattern_color = pattern(i,j,width,height);
            for(int k=0;k<pattern_color.size();k++){
                output_stream << pattern_color[k] << " ";
                print_count++;
                if(print_count % line_length == 0){
                    output_stream << "\n";
                }
            }
            pixel_count++;
        }
        progress.update();
    }
    //--------------------------------------//
    output_stream.close();
    return 0;
    //std:
}

