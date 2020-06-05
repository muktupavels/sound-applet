/*
 * Copyright (C) 2020 Alberts Muktupāvels
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#include "config.h"

#include <gtk/gtk.h>

#include "gf-sound-applet.h"

int
main (int   argc,
      char *argv[])
{
  GfSoundApplet *applet;

  gtk_init (&argc, &argv);

  applet = gf_sound_applet_new ();

  gtk_main ();

  g_clear_object (&applet);

  return EXIT_SUCCESS;
}
