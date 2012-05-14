<?php

// thanks to Aaron Tan and team at the Faculty of Architecture, Building and Planning, University of Melbourne, and Paul Tagell and team at Marketing and Communications, University of Melbourne - Media Insights 2011

/*
 * generic variables:
 * $attributes_array
 * $title_attributes_array
 * $content_attributes_array
 * $classes_array
 *  Array of html class attribute values. It is flattened into a string within the variable $classes. 
 * $title_prefix
 *  An array containing additional output populated by modules, intended to be displayed in front of the main title tag that appears in the template.
 * $title_suffix
 *  An array containing additional output populated by modules, intended to be displayed after the main title tag that appears in the template.
 * $id
 *  The placement of the template. Each time the template is used, it is incremented by one.
 * $zebra
 *  Either "odd" or "even". Alternate each time the template is used.
 * $directory
 *  The theme path relative to the base install. example: "sites/all/themes/myTheme"
 * $is_admin
 *  Boolean returns TRUE when the visitor is a site administrator.
 * $is_front
 *  Boolean returns TRUE when viewing the front page of the site.
 * $logged_in
 *  Boolean returns TRUE when the visitor is a member of the site, logged in and authenticated.
 * $db_is_active
 *  Boolean returns TRUE when the database is active and running. This is only useful for theming in maintenance mode where the site may run into database problems.
 * $user
 *  The user object containing data for the current visitor. Some of the data contained here may not be safe. Be sure to pass potentially dangerous strings through check_plain.
 *  
 * Regions:
 *  regions[newsbanner]	= Newsbanner
 *  regions[help]		= Help
 *  regions[content]	= Content
 *  regions[navigation]	= Navigation
 *  regions[column1]	= Column 1
 *  regions[column2]	= Column 2
 *  regions[column3]	= Column 3
 *  regions[column4]	= Column 4
 * 
*/

?><!DOCTYPE HTML>
<html lang="en">
<head>

<?php print $head; ?>

<title><?php print $head_title; ?></title>

<?php 

if(drupal_get_title() != '') { 
	$page_title = drupal_get_title(); } else { $page_title = ''; 
}

$site_name = variable_get('site_name', '');

?>

<meta charset="utf-8">
<meta http-equiv="X-UA-Compatible" content="IE=edge,chrome=1">

<title><?php print $site_name . ' | ' . $page_title; ?></title>  

<!-- SEO relevant meta data to describe content of page -->
	<meta name="DC.Title" content="<?php print $site_name . ' | ' . $page_title; ?>">
	<meta name="keywords" content="<?php if(variable_get('unimelb_settings_meta-keywords')) { print variable_get('unimelb_settings_meta-keywords') . ', ' . $page_title . ', ' . $site_name; } ?>">
	<meta name="description" content="<?php print $site_name . ': ' . $page_title; if($is_front && variable_get('unimelb_settings_ht-right')) { print ' - ' . variable_get('unimelb_settings_ht-right'); } ?>">
	<meta name="DC.Description" content="<?php print $site_name . ': ' . $page_title; if($is_front && variable_get('unimelb_settings_ht-right')) { print ' - ' . variable_get('unimelb_settings_ht-right'); } ?>">
<!-- End SEO relevant meta data -->

<!-- Authoriser and maintainer related meta data - developers, don't forget humans.txt -->
	<meta name="DC.Creator" content="<?php if(variable_get('unimelb_settings_maint-name')) { print variable_get('unimelb_settings_maint-name') . ', '; } print $site_name; ?>">
	<meta name="DC.Contributor" content="<?php if(variable_get('unimelb_settings_maint-name')) { print variable_get('unimelb_settings_maint-name') . ', '; }  print $site_name; ?>">
	<meta name="author" content="<?php if(variable_get('unimelb_settings_maint-name')) { print variable_get('unimelb_settings_maint-name') . ', '; }  print $site_name; ?>">
	<meta name="UM.Authoriser.Name" content="<?php if(variable_get('unimelb_settings_auth-name')) { print variable_get('unimelb_settings_auth-name'); } ?>">
	<meta name="UM.Authoriser.Title" content="<?php if(variable_get('unimelb_settings_auth-name')) { print variable_get('unimelb_settings_auth-name'); } ?>">
	<meta name="UM.Maintainer.Name" content="<?php if(variable_get('unimelb_settings_maint-name')) { print variable_get('unimelb_settings_maint-name'); } ?>">
	<meta name="UM.Maintainer.Department" content="<?php if(variable_get('unimelb_settings_maint-name')) { print variable_get('unimelb_settings_maint-name'); } ?>">
	<meta name="UM.Maintainer.Email" content="<?php if(variable_get('unimelb_settings_ad-email')) { print variable_get('unimelb_settings_ad-email'); } ?>">
<!-- End authoriser and maintainer meta data -->

<!-- Static meta data   -->
	<meta name="DC.Rights" content="http://www.unimelb.edu.au/disclaimer">
	<meta name="DC.Publisher" content="The University of Melbourne">
	<meta name="DC.Format" content="text/html">
	<meta name="DC.Language" content="en">
	<meta name="DC.Identifier" content="http://www.unimelb.edu.au/">
<!-- End static meta data -->

<!-- Meta data to be autofilled -->
	<meta name="DC.Date" content="DATE">
	<meta name="DC.Date.Modified" content="DATE">
<!-- End meta data to be autofilled -->

	<meta content="width=device-width; initial-scale=0.67;" name="viewport">

<?php print $styles; ?>

<?php // $files_directory = '/' . file_stream_wrapper_get_instance_by_uri('public://')->getDirectoryPath() . '/'; ?>

<!--[if lt IE 9]>
	<script type="text/javascript" src="http://html5shiv.googlecode.com/svn/trunk/html5.js"></script>
<![endif]-->

<?php print $scripts; ?>

</head>

<body class="<?php print $classes; ?>" <?php if($attributes) { print ' ' . $attributes; } ?>>

<?php print $page_top; ?>
<?php print $page; ?>
<?php print $page_bottom; ?>

</body>

</html>