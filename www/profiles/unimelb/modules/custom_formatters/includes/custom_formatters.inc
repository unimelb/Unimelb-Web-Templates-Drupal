<?php
/**
 * @file
 * Custom Formatters module integration.
 */

/**
 * Implements hook_custom_formatters_engine().
 */
function custom_formatters_custom_formatters_engine_info() {
  $engines = array();

  // PHP engine.
  $engines['php'] = array(
    'label' => t('PHP'),
    'callbacks' => array(
      'settings form' => 'custom_formatters_engine_php_settings_form',
      'render' => 'custom_formatters_engine_php_render',
      'export' => 'custom_formatters_engine_php_export',
      'help' => 'custom_formatters_engine_php_help',
    ),
    'file' => drupal_get_path('module', 'custom_formatters') . '/engines/php.inc',
  );

  return $engines;
}

/**
 * Implements hook_custom_formatters_defaults().
 */
function custom_formatters_custom_formatters_defaults() {
  $formatters = array();

  $formatter = new stdClass;
  $formatter->disabled = TRUE; /* Edit this to true to make a default formatter disabled initially */
  $formatter->api_version = 2;
  $formatter->name = 'example_php_image';
  $formatter->label = 'Example: Image (PHP)';
  $formatter->description = 'A PHP example formatter; Display a Thumbnail image linked to a Large image.';
  $formatter->mode = 'php';
  $formatter->field_types = 'image';
  $formatter->code = '$element = array();

// Formatter settings.
$settings = $variables[\'#display\'][\'settings\'];

foreach (element_children($variables[\'#items\']) as $delta) {
  $item = $variables[\'#items\'][$delta];

  $element[$delta] = array(
    \'#type\' => \'link\',
    \'#href\' => file_create_url(image_style_path($settings[\'image_style_destination\'], $item[\'uri\'])),
    \'#title\' => theme(\'image_style\', array(
      \'style_name\' => $settings[\'image_style_source\'],
      \'path\' => $item[\'uri\'],
    )),
    \'#options\' => array(
      \'html\' => TRUE,
    ),
  );
}

return $element;';
  $formatter->fapi = '$form = array();
$form[\'image_style_destination\'] = array(
  \'#weight\' => \'1\',
  \'#multiple_toggle\' => \'1\',
  \'#key_type_toggled\' => \'1\',
  \'#default_value\' => \'large\',
  \'#options\' => array(
    \'thumbnail\' => t(\'thumbnail\'),
    \'medium\' => t(\'medium\'),
    \'large\' => t(\'large\'),
  ),
  \'#type\' => \'select\',
  \'#title\' => t(\'Destination image style\'),
);
$form[\'image_style_source\'] = array(
  \'#required\' => \'0\',
  \'#default_value\' => \'thumbnail\',
  \'#options\' => array(
    \'thumbnail\' => t(\'thumbnail\'),
    \'medium\' => t(\'medium\'),
    \'large\' => t(\'large\'),
  ),
  \'#type\' => \'select\',
  \'#multiple_toggle\' => \'1\',
  \'#title\' => t(\'Source image style\'),
  \'#multiple\' => \'0\',
  \'#weight\' => \'1\',
  \'#key_type_toggled\' => \'1\',
);
';
  $formatters['example_php_image'] = $formatter;

  $formatter = new stdClass;
  $formatter->disabled = TRUE; /* Edit this to true to make a default formatter disabled initially */
  $formatter->api_version = 2;
  $formatter->name = 'example_token_image';
  $formatter->label = 'Example: Image (HTML + Token)';
  $formatter->description = 'A HTML + Tokens example formatter; Display a Thumbnail image linked to a Large image.';
  $formatter->mode = 'token';
  $formatter->field_types = 'image';
  $formatter->code = '<a href="[image-field-value:styles:url:large]"><img src="[image-field-value:styles:url:thumbnail]" alt="[image-field-value:alt]" title="[image-field-value:title]" /></a>';
  $formatters['example_token_image'] = $formatter;

  return $formatters;
}

/**
 * Implements hook_custom_formatters_theme_alter().
 */
function custom_formatters_custom_formatters_theme_alter(&$theme) {
  $engines = module_invoke_all('custom_formatters_engine_info');
  foreach (element_children($engines) as $engine) {
    if (isset($engines[$engine]['file']) && file_exists($engines[$engine]['file'])) {
      require_once $engines[$engine]['file'];
    }
    if (function_exists($function = "custom_formatters_engine_{$engine}_theme_alter")) {
      $function($theme);
    }
  }
}
