/* GStreamer
 * Copyright (C) <1999> Erik Walthinsen <omega@cse.ogi.edu>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Library General Public
 * License as published by the Free Software Foundation; either
 * version 2 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Library General Public License for more details.
 *
 * You should have received a copy of the GNU Library General Public
 * License along with this library; if not, write to the
 * Free Software Foundation, Inc., 59 Temple Place - Suite 330,
 * Boston, MA 02111-1307, USA.
 */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <gst/gst.h>
#include <gst/riff/riff-read.h>
#include "gst/gst-i18n-plugin.h"

#include "gstasfdemux.h"
/* #include "gstasfmux.h" */

static gboolean
plugin_init (GstPlugin * plugin)
{
#ifdef ENABLE_NLS
  setlocale (LC_ALL, "");
  bindtextdomain (GETTEXT_PACKAGE, LOCALEDIR);
#endif /* ENABLE_NLS */

  gst_riff_init ();

  if (!gst_element_register (plugin, "asfdemux", GST_RANK_SECONDARY,
          GST_TYPE_ASF_DEMUX)) {
    return FALSE;
  }
/*
  if (!gst_element_register (plugin, "asfmux", GST_RANK_NONE, GST_TYPE_ASFMUX))
    return FALSE;
*/

  return TRUE;
}

GST_PLUGIN_DEFINE (GST_VERSION_MAJOR,
    GST_VERSION_MINOR,
    "asf",
    "Demuxes and muxes audio and video in Microsofts ASF format",
    plugin_init, VERSION, GST_LICENSE, GST_PACKAGE_NAME, GST_PACKAGE_ORIGIN)
