#include <string>

namespace cppgram
{
    typedef long id_32;
    typedef long long id_64;
    typedef unsigned long date_unix;
    enum chat_type
    {
        type_private,
        type_group,
        type_supergroup,
        type_channel
    };

    struct chat
    {
        id_64 chat_id;
        chat_type type;
        char* title,
        username,
        first_name,
        last_name;
    } chat;

    struct user
    {
        id_32 user_id;
        char* first_name,
        last_name,
        username;
    } user;

    struct messageEntity
    {
        //messageEntity_type type;
        int offset;
        int lenght;
        char* url;
        struct user* user;
    } messageEntity;

    struct message
    {
        id_32 message_id;
        struct user* from;
        date_unix date;
        struct chat* chat;
        struct user* forward_from;
        struct chat* forward_from_chat;
        date_unix forward_date;
        struct message* reply_to_message;
        date_unix edit_date;
        char* text;
        struct messageEntity* (entities[]);
        //struct attachment* message_data;
    } message;

    typedef union update_t {
        struct message* message;
        struct callbackQuery* callbackQuery;

        //inlineQueries

    } update_t ;
}
