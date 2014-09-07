/*****************************************************************************
 * libvlc_MediaLibrary.hpp: MediaLibrary API
 *****************************************************************************
 * Copyright © 2014 the VideoLAN team
 *
 * Authors: Alexey Sokolov <alexey@alexeysokolov.co.cc>
 *          Hugo Beauzée-Luyssen <hugo@beauzee.fr>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/

#ifndef LIBVLC_CXX_MEDIALIBRARY_H
#define LIBVLC_CXX_MEDIALIBRARY_H

#include <common.hpp>
#include "Internal.hpp"

namespace VLC
{

class MediaLibrary : public Internal<libvlc_media_library_t>
{
public:
    /**
     * Create an new Media Library object
     *
     * \param p_instance  the libvlc instance
     */
    static MediaLibrary* create(Instance & p_instance);
    /**
     * Copy libvlc_media_library_t from another to new MediaLibrary object.
     * \param another existing MediaLibrary
     */
    MediaLibrary(const MediaLibrary& another);

    /**
     * Copy libvlc_media_library_t from another MediaLibrary
     * to this MediaLibrary
     * \param another existing MediaLibrary
     */
    const MediaLibrary& operator=(const MediaLibrary& another);

    /**
     * Check if 2 MediaLibrary objects contain the same libvlc_media_library_t.
     * \param another another MediaLibrary
     * \return true if they contain the same libvlc_media_library_t
     */
    bool operator==(const MediaLibrary& another) const;

    ~MediaLibrary();

    /**
     * Load media library.
     *
     * \return 0 on success, -1 on error
     */
    int load();

private:
    MediaLibrary(InternalPtr ptr);
    /**
     * Release media library object. This functions decrements the reference
     * count of the media library object. If it reaches 0, then the object
     * will be released.
     */
    void release();

    /**
     * Retain a reference to a media library object. This function will
     * increment the reference counting for this object. Use
     * MediaLibrary::release() to decrement the reference count.
     */
    void retain();
};

} // namespace VLC

#endif
