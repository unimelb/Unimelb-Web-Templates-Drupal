<?php
/**
 * @file
 * unimelb_content_types.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function unimelb_content_types_taxonomy_default_vocabularies() {
  return array(
    'organisational_units' => array(
      'name' => 'Organisational units',
      'machine_name' => 'organisational_units',
      'description' => '',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
    ),
  );
}
