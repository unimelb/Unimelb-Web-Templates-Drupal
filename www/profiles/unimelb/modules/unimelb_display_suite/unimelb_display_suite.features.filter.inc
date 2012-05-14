<?php
/**
 * @file
 * unimelb_display_suite.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function unimelb_display_suite_filter_default_formats() {
  $formats = array();

  // Exported format: Display Suite code
  $formats['ds_code'] = array(
    'format' => 'ds_code',
    'name' => 'Display Suite code',
    'cache' => '1',
    'status' => '1',
    'weight' => '12',
    'filters' => array(),
  );

  return $formats;
}
