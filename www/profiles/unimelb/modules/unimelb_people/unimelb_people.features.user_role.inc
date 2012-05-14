<?php
/**
 * @file
 * unimelb_people.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function unimelb_people_user_default_roles() {
  $roles = array();

  // Exported role: Admin
  $roles['Admin'] = array(
    'name' => 'Admin',
    'weight' => '5',
  );

  // Exported role: Editor
  $roles['Editor'] = array(
    'name' => 'Editor',
    'weight' => '4',
  );

  // Exported role: System
  $roles['System'] = array(
    'name' => 'System',
    'weight' => '6',
  );

  return $roles;
}
