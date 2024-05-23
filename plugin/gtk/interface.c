/*
 * DO NOT EDIT THIS FILE - it is generated by Glade.
 */

#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <stdio.h>

#include <gdk/gdkkeysyms.h>
#include <gtk/gtk.h>

#include "callbacks.h"
#include "interface.h"
#include "support.h"

#define GLADE_HOOKUP_OBJECT(component,widget,name) \
  g_object_set_data_full (G_OBJECT (component), name, \
    gtk_widget_ref (widget), (GDestroyNotify) gtk_widget_unref)

#define GLADE_HOOKUP_OBJECT_NO_REF(component,widget,name) \
  g_object_set_data (G_OBJECT (component), name, widget)

GtkWidget*
create_window1 (void)
{
  GtkWidget *window1;
  GtkWidget *vbox1;
  GtkWidget *menubar1;
  GtkWidget *menuitem4;
  GtkWidget *menu4;
  GtkWidget *new1;
  GtkWidget *open1;
  GtkWidget *save1;
  GtkWidget *save_as1;
  GtkWidget *separatormenuitem1;
  GtkWidget *quit1;
  GtkWidget *menuitem5;
  GtkWidget *menu5;
  GtkWidget *cut1;
  GtkWidget *copy1;
  GtkWidget *paste1;
  GtkWidget *delete1;
  GtkWidget *menuitem6;
  GtkWidget *menu6;
  GtkWidget *menuitem7;
  GtkWidget *menu7;
  GtkWidget *about1;
  GtkWidget *hpaned1;
  GtkWidget *vbox2;
  GtkWidget *hbox2;
  GtkWidget *drawingarea2;
  GtkWidget *scrolledwindow3;
  GtkWidget *treeview1;
  GtkWidget *toolbar1;
  GtkWidget *toolitem1;
  GtkWidget *label1;
  GtkWidget *toolitem2;
  GtkWidget *label2;
  GtkWidget *toolitem3;
  GtkWidget *button1;
  GtkWidget *scrolledwindow4;
  GtkWidget *treeview2;
  GtkWidget *drawingarea1;
  GtkAccelGroup *accel_group;

  accel_group = gtk_accel_group_new ();

  window1 = gtk_window_new (GTK_WINDOW_TOPLEVEL);
  gtk_window_set_title (GTK_WINDOW (window1), "DotEdit");

  vbox1 = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (vbox1);
  gtk_container_add (GTK_CONTAINER (window1), vbox1);

  menubar1 = gtk_menu_bar_new ();
  gtk_widget_show (menubar1);
  gtk_box_pack_start (GTK_BOX (vbox1), menubar1, FALSE, FALSE, 0);

  menuitem4 = gtk_menu_item_new_with_mnemonic (_("_File"));
  gtk_widget_show (menuitem4);
  gtk_container_add (GTK_CONTAINER (menubar1), menuitem4);

  menu4 = gtk_menu_new ();
  gtk_menu_item_set_submenu (GTK_MENU_ITEM (menuitem4), menu4);

  new1 = gtk_image_menu_item_new_from_stock ("gtk-new", accel_group);
  gtk_widget_show (new1);
  gtk_container_add (GTK_CONTAINER (menu4), new1);

  open1 = gtk_image_menu_item_new_from_stock ("gtk-open", accel_group);
  gtk_widget_show (open1);
  gtk_container_add (GTK_CONTAINER (menu4), open1);

  save1 = gtk_image_menu_item_new_from_stock ("gtk-save", accel_group);
  gtk_widget_show (save1);
  gtk_container_add (GTK_CONTAINER (menu4), save1);

  save_as1 = gtk_image_menu_item_new_from_stock ("gtk-save-as", accel_group);
  gtk_widget_show (save_as1);
  gtk_container_add (GTK_CONTAINER (menu4), save_as1);

  separatormenuitem1 = gtk_separator_menu_item_new ();
  gtk_widget_show (separatormenuitem1);
  gtk_container_add (GTK_CONTAINER (menu4), separatormenuitem1);
  gtk_widget_set_sensitive (separatormenuitem1, FALSE);

  quit1 = gtk_image_menu_item_new_from_stock ("gtk-quit", accel_group);
  gtk_widget_show (quit1);
  gtk_container_add (GTK_CONTAINER (menu4), quit1);

  menuitem5 = gtk_menu_item_new_with_mnemonic (_("_Edit"));
  gtk_widget_show (menuitem5);
  gtk_container_add (GTK_CONTAINER (menubar1), menuitem5);

  menu5 = gtk_menu_new ();
  gtk_menu_item_set_submenu (GTK_MENU_ITEM (menuitem5), menu5);

  cut1 = gtk_image_menu_item_new_from_stock ("gtk-cut", accel_group);
  gtk_widget_show (cut1);
  gtk_container_add (GTK_CONTAINER (menu5), cut1);

  copy1 = gtk_image_menu_item_new_from_stock ("gtk-copy", accel_group);
  gtk_widget_show (copy1);
  gtk_container_add (GTK_CONTAINER (menu5), copy1);

  paste1 = gtk_image_menu_item_new_from_stock ("gtk-paste", accel_group);
  gtk_widget_show (paste1);
  gtk_container_add (GTK_CONTAINER (menu5), paste1);

  delete1 = gtk_image_menu_item_new_from_stock ("gtk-delete", accel_group);
  gtk_widget_show (delete1);
  gtk_container_add (GTK_CONTAINER (menu5), delete1);

  menuitem6 = gtk_menu_item_new_with_mnemonic (_("_View"));
  gtk_widget_show (menuitem6);
  gtk_container_add (GTK_CONTAINER (menubar1), menuitem6);

  menu6 = gtk_menu_new ();
  gtk_menu_item_set_submenu (GTK_MENU_ITEM (menuitem6), menu6);

  menuitem7 = gtk_menu_item_new_with_mnemonic (_("_Help"));
  gtk_widget_show (menuitem7);
  gtk_container_add (GTK_CONTAINER (menubar1), menuitem7);

  menu7 = gtk_menu_new ();
  gtk_menu_item_set_submenu (GTK_MENU_ITEM (menuitem7), menu7);

  about1 = gtk_menu_item_new_with_mnemonic (_("_About"));
  gtk_widget_show (about1);
  gtk_container_add (GTK_CONTAINER (menu7), about1);

  hpaned1 = gtk_hpaned_new ();
  gtk_widget_show (hpaned1);
  gtk_box_pack_start (GTK_BOX (vbox1), hpaned1, TRUE, TRUE, 0);
  gtk_paned_set_position (GTK_PANED (hpaned1), 0);

  vbox2 = gtk_vbox_new (FALSE, 0);
  gtk_widget_show (vbox2);
  gtk_paned_pack1 (GTK_PANED (hpaned1), vbox2, TRUE, TRUE);

  hbox2 = gtk_hbox_new (FALSE, 0);
  gtk_widget_show (hbox2);
  gtk_box_pack_start (GTK_BOX (vbox2), hbox2, FALSE, FALSE, 0);

  drawingarea2 = gtk_drawing_area_new ();
  gtk_widget_show (drawingarea2);
  gtk_box_pack_start (GTK_BOX (hbox2), drawingarea2, FALSE, FALSE, 1);
  gtk_widget_set_size_request (drawingarea2, 100, 100);

  scrolledwindow3 = gtk_scrolled_window_new (NULL, NULL);
  gtk_widget_show (scrolledwindow3);
  gtk_box_pack_end (GTK_BOX (hbox2), scrolledwindow3, TRUE, TRUE, 1);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrolledwindow3), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
  gtk_scrolled_window_set_shadow_type (GTK_SCROLLED_WINDOW (scrolledwindow3), GTK_SHADOW_IN);

  treeview1 = gtk_tree_view_new ();
  gtk_widget_show (treeview1);
  gtk_container_add (GTK_CONTAINER (scrolledwindow3), treeview1);
  gtk_tree_view_set_headers_visible (GTK_TREE_VIEW (treeview1), FALSE);

  toolbar1 = gtk_toolbar_new ();
  gtk_widget_show (toolbar1);
  gtk_box_pack_start (GTK_BOX (vbox2), toolbar1, FALSE, FALSE, 0);
  gtk_toolbar_set_style (GTK_TOOLBAR (toolbar1), GTK_TOOLBAR_ICONS);

  toolitem1 = (GtkWidget*) gtk_tool_item_new ();
  gtk_widget_show (toolitem1);
  gtk_container_add (GTK_CONTAINER (toolbar1), toolitem1);

  label1 = gtk_label_new (_("type - name"));
  gtk_widget_show (label1);
  gtk_container_add (GTK_CONTAINER (toolitem1), label1);

  toolitem2 = (GtkWidget*) gtk_tool_item_new ();
  gtk_widget_show (toolitem2);
  gtk_tool_item_set_expand (GTK_TOOL_ITEM (toolitem2), TRUE);
  gtk_container_add (GTK_CONTAINER (toolbar1), toolitem2);

  label2 = gtk_label_new ("");
  gtk_widget_show (label2);
  gtk_container_add (GTK_CONTAINER (toolitem2), label2);

  toolitem3 = (GtkWidget*) gtk_tool_item_new ();
  gtk_widget_show (toolitem3);
  gtk_container_add (GTK_CONTAINER (toolbar1), toolitem3);

  button1 = gtk_button_new_with_mnemonic (_("Delete"));
  gtk_widget_show (button1);
  gtk_container_add (GTK_CONTAINER (toolitem3), button1);
  gtk_button_set_focus_on_click (GTK_BUTTON (button1), FALSE);

  scrolledwindow4 = gtk_scrolled_window_new (NULL, NULL);
  gtk_widget_show (scrolledwindow4);
  gtk_box_pack_start (GTK_BOX (vbox2), scrolledwindow4, TRUE, TRUE, 1);
  gtk_scrolled_window_set_policy (GTK_SCROLLED_WINDOW (scrolledwindow4), GTK_POLICY_AUTOMATIC, GTK_POLICY_AUTOMATIC);
  gtk_scrolled_window_set_shadow_type (GTK_SCROLLED_WINDOW (scrolledwindow4), GTK_SHADOW_IN);

  treeview2 = gtk_tree_view_new ();
  gtk_widget_show (treeview2);
  gtk_container_add (GTK_CONTAINER (scrolledwindow4), treeview2);
  gtk_tree_view_set_headers_visible (GTK_TREE_VIEW (treeview2), FALSE);
  gtk_tree_view_set_rules_hint (GTK_TREE_VIEW (treeview2), TRUE);

  drawingarea1 = gtk_drawing_area_new ();
  gtk_widget_show (drawingarea1);
  gtk_paned_pack2 (GTK_PANED (hpaned1), drawingarea1, TRUE, TRUE);
  gtk_widget_set_size_request (drawingarea1, 300, 300);
  gtk_widget_set_events (drawingarea1, GDK_EXPOSURE_MASK | GDK_POINTER_MOTION_MASK | GDK_BUTTON_MOTION_MASK | GDK_BUTTON_PRESS_MASK | GDK_BUTTON_RELEASE_MASK | GDK_ENTER_NOTIFY_MASK | GDK_LEAVE_NOTIFY_MASK);

  g_signal_connect ((gpointer) window1, "delete_event",
                    G_CALLBACK (on_window1_delete_event),
                    NULL);
  g_signal_connect_swapped ((gpointer) new1, "activate",
                            G_CALLBACK (on_new1_activate),
                            GTK_OBJECT (window1));
  g_signal_connect_swapped ((gpointer) open1, "activate",
                            G_CALLBACK (on_open1_activate),
                            GTK_OBJECT (window1));
  g_signal_connect_swapped ((gpointer) save1, "activate",
                            G_CALLBACK (on_save1_activate),
                            GTK_OBJECT (window1));
  g_signal_connect_swapped ((gpointer) save_as1, "activate",
                            G_CALLBACK (on_save_as1_activate),
                            GTK_OBJECT (window1));
  g_signal_connect ((gpointer) quit1, "activate",
                    G_CALLBACK (on_quit1_activate),
                    NULL);
  g_signal_connect ((gpointer) cut1, "activate",
                    G_CALLBACK (on_cut1_activate),
                    NULL);
  g_signal_connect ((gpointer) copy1, "activate",
                    G_CALLBACK (on_copy1_activate),
                    NULL);
  g_signal_connect ((gpointer) paste1, "activate",
                    G_CALLBACK (on_paste1_activate),
                    NULL);
  g_signal_connect ((gpointer) delete1, "activate",
                    G_CALLBACK (on_delete1_activate),
                    NULL);
  g_signal_connect ((gpointer) about1, "activate",
                    G_CALLBACK (on_about1_activate),
                    NULL);
  g_signal_connect ((gpointer) drawingarea2, "expose_event",
                    G_CALLBACK (on_drawingarea2_expose_event),
                    NULL);
  g_signal_connect ((gpointer) drawingarea2, "motion_notify_event",
                    G_CALLBACK (on_drawingarea2_motion_notify_event),
                    NULL);
  g_signal_connect ((gpointer) button1, "button_press_event",
                    G_CALLBACK (on_button1_button_press_event),
                    NULL);
  g_signal_connect ((gpointer) drawingarea1, "expose_event",
                    G_CALLBACK (on_drawingarea1_expose_event),
                    NULL);
  g_signal_connect ((gpointer) drawingarea1, "motion_notify_event",
                    G_CALLBACK (on_drawingarea1_motion_notify_event),
                    NULL);
  g_signal_connect ((gpointer) drawingarea1, "configure_event",
                    G_CALLBACK (on_drawingarea1_configure_event),
                    NULL);
  g_signal_connect ((gpointer) drawingarea1, "button_press_event",
                    G_CALLBACK (on_drawingarea1_button_press_event),
                    NULL);
  g_signal_connect ((gpointer) drawingarea1, "button_release_event",
                    G_CALLBACK (on_drawingarea1_button_release_event),
                    NULL);
  g_signal_connect ((gpointer) drawingarea1, "scroll_event",
                    G_CALLBACK (on_drawingarea1_scroll_event),
                    NULL);

  /* Store pointers to all widgets, for use by lookup_widget(). */
  GLADE_HOOKUP_OBJECT_NO_REF (window1, window1, "window1");
  GLADE_HOOKUP_OBJECT (window1, vbox1, "vbox1");
  GLADE_HOOKUP_OBJECT (window1, menubar1, "menubar1");
  GLADE_HOOKUP_OBJECT (window1, menuitem4, "menuitem4");
  GLADE_HOOKUP_OBJECT (window1, menu4, "menu4");
  GLADE_HOOKUP_OBJECT (window1, new1, "new1");
  GLADE_HOOKUP_OBJECT (window1, open1, "open1");
  GLADE_HOOKUP_OBJECT (window1, save1, "save1");
  GLADE_HOOKUP_OBJECT (window1, save_as1, "save_as1");
  GLADE_HOOKUP_OBJECT (window1, separatormenuitem1, "separatormenuitem1");
  GLADE_HOOKUP_OBJECT (window1, quit1, "quit1");
  GLADE_HOOKUP_OBJECT (window1, menuitem5, "menuitem5");
  GLADE_HOOKUP_OBJECT (window1, menu5, "menu5");
  GLADE_HOOKUP_OBJECT (window1, cut1, "cut1");
  GLADE_HOOKUP_OBJECT (window1, copy1, "copy1");
  GLADE_HOOKUP_OBJECT (window1, paste1, "paste1");
  GLADE_HOOKUP_OBJECT (window1, delete1, "delete1");
  GLADE_HOOKUP_OBJECT (window1, menuitem6, "menuitem6");
  GLADE_HOOKUP_OBJECT (window1, menu6, "menu6");
  GLADE_HOOKUP_OBJECT (window1, menuitem7, "menuitem7");
  GLADE_HOOKUP_OBJECT (window1, menu7, "menu7");
  GLADE_HOOKUP_OBJECT (window1, about1, "about1");
  GLADE_HOOKUP_OBJECT (window1, hpaned1, "hpaned1");
  GLADE_HOOKUP_OBJECT (window1, vbox2, "vbox2");
  GLADE_HOOKUP_OBJECT (window1, hbox2, "hbox2");
  GLADE_HOOKUP_OBJECT (window1, drawingarea2, "drawingarea2");
  GLADE_HOOKUP_OBJECT (window1, scrolledwindow3, "scrolledwindow3");
  GLADE_HOOKUP_OBJECT (window1, treeview1, "treeview1");
  GLADE_HOOKUP_OBJECT (window1, toolbar1, "toolbar1");
  GLADE_HOOKUP_OBJECT (window1, toolitem1, "toolitem1");
  GLADE_HOOKUP_OBJECT (window1, label1, "label1");
  GLADE_HOOKUP_OBJECT (window1, toolitem2, "toolitem2");
  GLADE_HOOKUP_OBJECT (window1, label2, "label2");
  GLADE_HOOKUP_OBJECT (window1, toolitem3, "toolitem3");
  GLADE_HOOKUP_OBJECT (window1, button1, "button1");
  GLADE_HOOKUP_OBJECT (window1, scrolledwindow4, "scrolledwindow4");
  GLADE_HOOKUP_OBJECT (window1, treeview2, "treeview2");
  GLADE_HOOKUP_OBJECT (window1, drawingarea1, "drawingarea1");

  gtk_window_add_accel_group (GTK_WINDOW (window1), accel_group);

  return window1;
}

