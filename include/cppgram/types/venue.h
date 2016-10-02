#ifndef CPPGRAM_VENUE_H
#define CPPGRAM_VENUE_H

#include <string>

#include <json/json.h>

#include "location.h"

namespace cppgram
{

/** \addtogroup Types
 * @{
 */

/** \brief This object represents a venue.
 * \details (https://core.telegram.org/bots/api#venue) */
struct venue
{
    /** @} */

    /** \brief Venue location */
    struct location *location;

    /** \brief Name of the venue */
    std::string title,

    /** \brief Address of the venue */
            address,

    /** \brief <i>Optional</i>. Foursquare identifier of the venue */
            foursquare_id;

    venue(Json::Value &venue)
            : location(new struct location(venue["location"])),
              title(venue["title"].asString()),
              address(venue["address"].asString()),
              foursquare_id(venue["foursquare_id"].asString())
    {}

    venue()
    {}

    ~venue()
    { delete location; }

};

}

#endif //CPPGRAM_VENUE_H
