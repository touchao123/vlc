/*
 * BaseRepresentation.cpp
 *****************************************************************************
 * Copyright (C) 2010 - 2011 Klagenfurt University
 *
 * Created on: Aug 10, 2010
 * Authors: Christopher Mueller <christopher.mueller@itec.uni-klu.ac.at>
 *          Christian Timmerer  <christian.timmerer@itec.uni-klu.ac.at>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU Lesser General Public License as published
 * by the Free Software Foundation; either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston MA 02110-1301, USA.
 *****************************************************************************/
#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include <cstdlib>

#include "BaseRepresentation.h"
#include "BaseAdaptationSet.h"
#include "SegmentTemplate.h"

using namespace adaptative::playlist;

BaseRepresentation::BaseRepresentation( BaseAdaptationSet *set, AbstractPlaylist *playlist_ ) :
                SegmentInformation( set ),
                playlist        ( playlist_ ),
                adaptationSet   ( set ),
                bandwidth       (0)
{
}

BaseRepresentation::~BaseRepresentation ()
{
}

uint64_t     BaseRepresentation::getBandwidth            () const
{
    return bandwidth;
}

void    BaseRepresentation::setBandwidth( uint64_t bandwidth )
{
    this->bandwidth = bandwidth;
}

std::vector<std::string> BaseRepresentation::toString(int indent) const
{
    std::vector<std::string> ret;
    std::string text(indent, ' ');
    text.append("Representation");
    ret.push_back(text);
    std::vector<ISegment *> list = getSegments();
    std::vector<ISegment *>::const_iterator l;
    for(l = list.begin(); l < list.end(); l++)
        ret.push_back((*l)->toString(indent + 1));

    return ret;
}

AbstractPlaylist * BaseRepresentation::getPlaylist() const
{
    return playlist;
}

std::string BaseRepresentation::contextualize(size_t, const std::string &component,
                                              const BaseSegmentTemplate *) const
{
    return component;
}
