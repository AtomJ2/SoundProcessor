#include "wavefc.h"

using namespace wavefc;

std::vector<int16_t> ReverseConvertor::reverse_sec(std::vector<int16_t> converted_second) {
    std::reverse(converted_second.begin(), converted_second.end());
    return converted_second;
}

void ReverseConvertor::convert(std::vector<std::string> command, std::string output_file_name) {
    wavefc::WaveReader reader(command.at(1));
    reader.read_header();
    wavefc::Writer writer(output_file_name);
    writer.write_header(reader.get_header());
    while (!reader.get_stream().eof())
        writer.write_string(this->reverse_sec(reader.read_second()));
}