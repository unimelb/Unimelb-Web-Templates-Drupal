<?php

// thanks to Aaron Tan and team at the Faculty of Architecture, Building and Planning, University of Melbourne, and Paul Tagell and team at Marketing and Communications, University of Melbourne - Media Insights 2011

/**
 * make Unimelb Settings variables available to js
 */

if(variable_get('unimelb_settings_site-name-short') && variable_get('unimelb_settings_site-name-short', '') != ''){
$site_name = variable_get('unimelb_settings_site-name-short');
$vars1 = array('sitename' => $site_name);
drupal_add_js($vars1, 'setting');
}

if(variable_get('unimelb_settings_parent-org-short') && variable_get('unimelb_settings_parent-org-short', '') != ''){
$parent_org = variable_get('unimelb_settings_parent-org-short');
$vars2 = array('parentorg' => $parent_org);
drupal_add_js($vars2, 'setting');
}

if(variable_get('unimelb_settings_parent-org-url') && variable_get('unimelb_settings_parent-org-url', '') != ''){
$parent_orgurl = variable_get('unimelb_settings_parent-org-url');
$vars3 = array('parentorgurl' => $parent_orgurl);
drupal_add_js($vars3, 'setting');
}

/**
 * remove width and height attributes from images
 */

function unimelb_theme_image($variables) {
  $attributes = $variables['attributes'];
  $attributes['src'] = file_create_url($variables['path']);

  // foreach (array('width', 'height', 'alt', 'title') as $key) {
foreach (array('alt', 'title') as $key) {
	
    if (isset($variables[$key])) {
      $attributes[$key] = $variables[$key];
    }
  }

  return '<img' . drupal_attributes($attributes) . ' />';
}


/**
 * Override or insert variables into the html template.
 *
 * @param $variables
 *   An array of variables to pass to the theme template. 
 * @param $hook
 *   The name of the template being rendered ("html" in this case.)
 */
function unimelb_preprocess_html(&$variables, $hook) {
	
/* remote js */

drupal_add_js('http://brand.unimelb.edu.au/global-header/js/injection.js', 'external');

/* local js */

drupal_add_js('http://brand.unimelb.edu.au/web-templates/1-1-0/js/complete.js', 'external');
drupal_add_js('/profiles/unimelb/themes/unimelb/js/unimelb_drupal_distro.js', 'external');

/* local css */

drupal_add_css('http://brand.unimelb.edu.au/web-templates/1-1-0/css/complete.css', array('group' => CSS_THEME, 'type' => 'external'));
drupal_add_css(drupal_get_path('theme', 'unimelb') . '/css/unimelb_drupal_distro.css', array('group' => CSS_THEME));

}

/**
 * Preprocess variables for region.tpl.php
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("region" in this case.)
 */
function unimelb_preprocess_region(&$variables, $hook) {
//	dsm($variables['region']);

	if ($variables['region'] == "above") {
	     $variables['classes_array'][] = 'above';
	}
	
}



/**
 * Override or insert variables into the page template.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("page" in this case.)
 */
function unimelb_preprocess_page(&$variables, $hook) {
 
// $variables['testvar'] = 'thistest';

// $variables['title'] = NULL; 

}
 

/**
 * Override or insert variables into the node templates.
 *
 * @param $variables
 *   An array of variables to pass to the theme template.
 * @param $hook
 *   The name of the template being rendered ("node" in this case.)
 */
function unimelb_preprocess_node(&$variables, $hook) {
  // Add $unpublished variable.
  $variables['unpublished'] = (!$variables['status']) ? TRUE : FALSE;

  // Add a class for the view mode.

    $variables['classes_array'][] = 'view-mode-' . $variables['view_mode'];

// $variables['title'] = NULL; 

  // Add a class to show node is authored by current user.
  if ($variables['uid'] && $variables['uid'] == $GLOBALS['user']->uid) {
    $variables['classes_array'][] = 'node-by-viewer';
  }


}


