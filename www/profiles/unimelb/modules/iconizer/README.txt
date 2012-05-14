1. Install ---------------------------------------------
  
  Install this module as other modules: copy iconizer/ directory into your
  "sites/all/modules" directory
  
  Admin-icons are avaiable for download from my Blog-post:
  http://thepanz.netsons.org
  Extract contents replacing ojld module's directory and admin_icons files
  
  The Admin_icons can't be included in this module due to GPL license issues.
  
  Then enable the module under:
    Administer > Site Building > Modules
  
  Change Icons display on/off in:
    Administer > Settings > Iconizer
  
2. Uninstall -------------------------------------------

  To uninstall use Drupal Modules manager:
    Administer > Modules
  
  To Fully remove Iconizer settings, also uninstall it:
    Admnister > Modules > Uninstall
  
3. Requirements ----------------------------------------
  
  To use this modules your Browser must support CSS1/2 and PNG transparency
  
  Read also about specific tecniquest requirements:
  
  - Admin icons     : http://www.askthecssguy.com/2006/12/showing_hyperlink_cues_with_cs_1.html
  - File types icons: http://pooliestudios.com/projects/iconize/
  - Protocols  icons: http://pooliestudios.com/projects/iconize/
  
  Admin Icons are taken from the Oxygen (KDE) progect
  Some of them have been edited/modified to try to represent the module's function.

5. Icons Overriding ------------------------------------
  If you need to override the files icons you can create a file called "files_icons-override.css"
  with your customizations, place it in the module folder and it will be loaded after the default one.
  
  There is an example file called "files_icons-override.css.example", take a look at it! :)
  Maybe you need to clear your cache before the override takes effect..

5. To-Do -----------------------------------------------
  
  Fix/Enable Icons Themeing