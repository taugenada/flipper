#include <furi.h>

#include <storage/storage.h>
#include <flipper_format/flipper_format_i.h>

int playlist_count_playlist_items(Storage* storage, const char* file_path) {
    FlipperFormat* format = flipper_format_file_alloc(storage);
    if(!flipper_format_file_open_existing(format, file_path)) {
        return -1;
    }
    int count = 0;
    string_t data;
    string_init(data);
    while(flipper_format_read_string(format, "sub", data)) {
        ++count;
    }
    flipper_format_file_close(format);
    string_clear(data);
    return count;
}
