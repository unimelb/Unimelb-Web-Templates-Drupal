<?php
/**
 * @file
 * unimelb_taxonomy_organisational_units.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function unimelb_taxonomy_organisational_units_taxonomy_default_vocabularies() {
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
