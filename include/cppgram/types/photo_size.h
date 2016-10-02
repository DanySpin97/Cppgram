#ifndef CPPGRAM_PHOTO_SIZE_H
#define CPPGRAM_PHOTO_SIZE_H

#include <string>
#include <json/json.h>

#include "integers.h"

namespace cppgram
{

/** \addtogroup Types
 * @{
 */

/** \brief A photo or thumbnail
 * \details This object represents one size of a photo or a file / sticker thumbnail. (https://core.telegram.org/bots/api#photosize) */
struct photoSize
{
    /** @} */

    /** \brief Unique identifier for this file */
    std::string file_id;

    /** \brief Photo width */
    uid_32 width,

    /** \brief Photo height */
            height,

    /** \brief <i>Optional</i>. File size */
            file_size;

    photoSize(Json::Value &photoSize)
            : file_id(photoSize["file_id"].asString()),
              width(photoSize["width"].asUInt()),
              height(photoSize["height"].asUInt())
    {
        if (!photoSize["file_size"].isNull())
            file_size = photoSize["file_size"].asUInt();

    };

    photoSize()
    {};

    ~photoSize()
    {};
};

}

#endif //CPPGRAM_PHOTO_SIZE_H