<?php
/**
 * @file
 * unimelb_display_suite.ds.inc
 */

/**
 * Implements hook_ds_view_modes_info().
 */
function unimelb_display_suite_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'event';
  $ds_view_mode->label = 'Event';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['event'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'profile';
  $ds_view_mode->label = 'Profile';
  $ds_view_mode->entities = array(
    'user' => 'user',
  );
  $export['profile'] = $ds_view_mode;

  return $export;
}
