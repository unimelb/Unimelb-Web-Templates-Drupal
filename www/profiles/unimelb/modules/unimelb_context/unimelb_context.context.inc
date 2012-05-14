<?php
/**
 * @file
 * unimelb_context.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function unimelb_context_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'archive';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'archive' => 'archive',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-zones_archive-archive' => array(
          'module' => 'views',
          'delta' => 'zones_archive-archive',
          'region' => 'content',
          'weight' => '18',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['archive'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'front';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '<front>' => '<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-zones_columns-home_column1' => array(
          'module' => 'views',
          'delta' => 'zones_columns-home_column1',
          'region' => 'home_column1',
          'weight' => '-10',
        ),
        'views-zones_columns-home_column2' => array(
          'module' => 'views',
          'delta' => 'zones_columns-home_column2',
          'region' => 'home_column2',
          'weight' => '-10',
        ),
        'views-zones_columns-home_column3' => array(
          'module' => 'views',
          'delta' => 'zones_columns-home_column3',
          'region' => 'home_column3',
          'weight' => '-10',
        ),
        'views-zones_columns-home_column4' => array(
          'module' => 'views',
          'delta' => 'zones_columns-home_column4',
          'region' => 'home_column4',
          'weight' => '-10',
        ),
      ),
    ),
    'theme_html' => array(
      'class' => 'home no-logo',
    ),
  );
  $context->condition_mode = 0;
  $export['front'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'news_and_events';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'news_and_events' => 'news_and_events',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-1f0a956f7f89374470a66ca7e6a378ec' => array(
          'module' => 'views',
          'delta' => '1f0a956f7f89374470a66ca7e6a378ec',
          'region' => 'content',
          'weight' => '9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;
  $export['news_and_events'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'not-front';
  $context->description = '';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '~<front>' => '~<front>',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'cck_blocks-field_aside' => array(
          'module' => 'cck_blocks',
          'delta' => 'field_aside',
          'region' => 'aside',
          'weight' => '-10',
        ),
        'views-zones_events-aside_events' => array(
          'module' => 'views',
          'delta' => 'zones_events-aside_events',
          'region' => 'aside',
          'weight' => '-10',
        ),
        'views-zones_subpages-aside_subpages' => array(
          'module' => 'views',
          'delta' => 'zones_subpages-aside_subpages',
          'region' => 'aside',
          'weight' => '-10',
        ),
      ),
    ),
    'theme_html' => array(
      'class' => 'blue no-logo',
    ),
  );
  $context->condition_mode = 0;
  $export['not-front'] = $context;

  return $export;
}
